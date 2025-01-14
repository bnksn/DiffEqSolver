## Requirements
- CMake.
- A C++ compiler with C++23 support.
- Python 3 (including Matplotlib and Numpy).
- Google Test
- vcpkg

## How to use
1. **Build** (see other section).
2. **Edit `config.txt`** (see other section).
3. **Run the binary** `./build/DiffEqSolver ../config.txt`.

   - `../config.txt` is the path of the config file relative to the binary.
   - There will be a console message if there is any numerical instabilitiy.

5. **Run Plot.py** `python3 ./src/Plot/Plot.py ../../build/data.txt`.

   - `../../build/data.txt` is the path of the result file relative to the python script. 

## How to build
1. **Clone the repository** `git clone https://github.com/bnksn/DiffEqSolver.git`.
2. **Navigate to the root directory** `cd DiffEqSolver`.
3. **Configure CMake** `cmake -B ./build ./build path/to/vcpkg/scripts/buildsystems.vcpkg.cmake`.
4. **Build** `cmake --build ./build` 

## How to configure `config.txt`
- The solver supports ODEs with either 2 or 3 variables.
- The solver will use the relevant config items depending on the ODE selected.
- Specify the ODE by changing the **solver** setting.
- Be sure to change the **dimension** setting accordingly.

| Setting | Description | Possible Values
|---|---|---|
| resultPath | Result output path relative to the binary. | Any valid path |
| dimension | Must match the dimension corresponding to the solver. | 2, 3 |
| solver | Which ODE to solve. | polynomial, trig, heat, advection, wave |
| boundaryCondition | Which boundary condition to use. | dirichlet, neumann |
| waveConstant | Constant used for wave solver. | Any double |
| advectionConstant | Constant used for advection solver. | Any double |
| heatConstant | Constant used for heat solver. | Any double |
| xFinal | The final xValue. Used for both 2D and 3D ODEs. | Any double > 0 |
| xNumSteps | Number of x steps used for discretisation. Used for both 2D and 3D ODEs. | Any int > 0 |
| yInitial | Value of y for x = 0. Used for 2D ODEs only. | Any double |
| zInitial | List of z values when y = 0. Used for 3D ODEs only. | List of doubles. Must agree with xNumSteps |
| yFinal | The final yValue. Used for 3D ODEs only. | Any double > 0 |
| yNumSteps | Number of y steps used for discretisation. Used for 3D ODEs only. | Any int > 0 |
| polynomialCoeffs | A + Bx + Cx^2 + ... | List of doubles |
| trigFunc | Which trig function to use for the trig solver. | sine, cosine, tangent |
| trigCoeffs | Atrig(Bx) | List of 2 doubles |

## How to test
1. **Build** (see other section).
2. **Run test binary** `./DiffEqSolverTests`

## To Do
- Use modules
- Add Tests

## Gallery
![me](https://github.com/bnksn/DiffEqSolver/blob/main/gallery/wavePlot.png)
![me](https://github.com/bnksn/DiffEqSolver/blob/main/gallery/waveAnim.gif)
