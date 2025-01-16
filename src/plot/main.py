import os
import argparse
import plot

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
            plot.plot2d(xVals, yVals)

        if dimension == 3:
            zVals: list[float] = [coord[2] for coord in allCoordsVals]

            plot.plot3d(xVals, yVals, zVals)
            plot.anim3d(xVals, yVals, zVals)
