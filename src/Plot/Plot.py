import matplotlib.pyplot as plt  # type: ignore
from matplotlib.animation import FuncAnimation  # type: ignore
import os
import numpy as np
import numpy.typing as npt
import argparse


def plot2d(xVals: list[float], yVals: list[float]) -> None:
    plt.plot(xVals, yVals)
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("X vs Y")
    plt.show()


def plot3d(xVals: list[float], yVals: list[float], zVals: list[float]) -> None:
    xValsUnique: npt.NDArray[np.float64] = np.unique(xVals)
    yValsUnique: npt.NDArray[np.float64] = np.unique(yVals)

    X, Y = np.meshgrid(xValsUnique, yValsUnique)

    Z = np.zeros_like(X)
    xCount = len(xValsUnique)
    for i in range(len(zVals)):
        Z[i // xCount][i % xCount] = zVals[i]

    fig: plt.Figure = plt.figure()
    ax: plt.Axes = fig.add_subplot(111, projection="3d")

    ax.plot_surface(X, Y, Z, cmap="inferno")

    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Z")
    ax.set_title("X vs Y vs Z")

    plt.show()


def anim3d(xVals: list[float], yVals: list[float], zVals: list[float]) -> None:
    xValsUnique: np.ndarray = np.unique(xVals)
    zValsNumpy: np.ndarray = np.array(zVals)

    fig, ax = plt.subplots()
    ax.set_xlabel("X")
    ax.set_ylabel("Z")
    ax.set_title("X vs Z over time (Y)")
    ax.set_ylim(min(zValsNumpy), max(zValsNumpy))

    xCount: int = len(xValsUnique)
    (line,) = ax.plot(xValsUnique, zValsNumpy[:xCount])

    def animate(i: int) -> tuple[plt.Line2D]:
        zIndexSlice: slice = slice(i * xCount, i * xCount + xCount)
        line.set_data(xValsUnique, zValsNumpy[zIndexSlice])

        return (line,)

    _ = FuncAnimation(fig, animate, frames=len(set(yVals)), interval=20)

    plt.show()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "relativePath", type=str, help="The relative path of the results"
    )
    args = parser.parse_args()
    currDir: str = os.path.dirname(os.path.abspath(__file__))

    with open(currDir + "/" + args.relativePath, "r") as dataFile:
        firstLine: str = dataFile.readline().strip()
        allCoords: list[str] = firstLine.split(" ")  # ["0,0,0", "1,1,2", ...]
        allCoordsVals: list[tuple[float, ...]] = [
            tuple(map(float, coord.split(","))) for coord in allCoords
        ]
        dimension: int = len(allCoordsVals[0])  # Deduce dimension from data

        xVals: list[float] = [coord[0] for coord in allCoordsVals]
        yVals: list[float] = [coord[1] for coord in allCoordsVals]

        if dimension == 2:
            plot2d(xVals, yVals)

        if dimension == 3:
            zVals: list[float] = [coord[2] for coord in allCoordsVals]

            plot3d(xVals, yVals, zVals)
            anim3d(xVals, yVals, zVals)
