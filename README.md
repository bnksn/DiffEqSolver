Differential equation solver that supports a range of 2D and 3D equations.\
Includes a Python script for result visualisation.

## Technical details
   - Core application built using the C++23 standard library
   - Developed with a focus on modern C++ techniques and best practices
   - Integrated with the vcpkg package manager
   - Includes a variety of unit tests (GTest)
   - Built with CMake and tested on multiple compilers (GCC, Clang, MSVC) and platforms (Linux, Windows) via a CI pipeline

## Requirements
- CMake
- A C++ compiler with C++23 support
- Python 3 (including Matplotlib and Numpy)
- Google Test
- vcpkg

## How to use
1. **Build** (see other section).
2. **Edit `config.txt`** (see other section).
3. **Run the binary** `./build/DiffEqSolver ../config.txt`.

   - `../config.txt` is the path of the config file relative to the binary.
   - There will be a console message if there is any numerical instabilitiy.

5. **Run Main.py** `python3 ./src/Plot/Main.py ../../build/data.txt`.

   - `../../build/data.txt` is the path of the result file relative to the python script. 

## How to build
1. **Clone the repository** `git clone https://github.com/bnksn/DiffEqSolver.git`.
2. **Navigate to the root directory** `cd DiffEqSolver`.
3. **Configure CMake** `cmake -B ./build -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`.
4. **Build** `cmake --build ./build` 

## How to configure `config.txt`
- The solver supports equations with either 2 or 3 variables.
- The solver will use the relevant config items depending on the equation selected.
- Specify the equation by changing the **solver** setting.
- Be sure to change the **dimension** setting accordingly.

| Setting | Description | Possible Values
|---|---|---|
| resultPath | Result output path relative to the binary. | Any valid path |
| dimension | Must match the dimension corresponding to the solver. | 2, 3 |
| solver | Which equation to solve. | polynomial, trig, heat, advection, wave |
| boundaryCondition | Which boundary condition to use. | dirichlet, neumann |
| waveConstant | Constant used for wave solver. | Any double |
| advectionConstant | Constant used for advection solver. | Any double |
| heatConstant | Constant used for heat solver. | Any double |
| xFinal | The final xValue. Used for both 2D and 3D equations. | Any double > 0 |
| xNumSteps | Number of x steps used for discretisation. Used for both 2D and 3D equations. | Any int > 0 |
| yInitial | Value of y for x = 0. Used for 2D equations only. | Any double |
| zInitial | List of z values when y = 0. Used for 3D equations only. | List of doubles. Must agree with xNumSteps |
| yFinal | The final yValue. Used for 3D equations only. | Any double > 0 |
| yNumSteps | Number of y steps used for discretisation. Used for 3D equations only. | Any int > 0 |
| polynomialCoeffs | A + Bx + Cx^2 + ... | List of doubles |
| trigFunc | Which trig function to use for the trig solver. | sine, cosine, tangent |
| trigCoeffs | Atrig(Bx) | List of 2 doubles |

## How to test
1. **Build** (see other section).
2. **Run CTest** `ctest --test-dir ./build --output-on-failure -C Debug`

## To Do
- Use modules

## Gallery
![me](https://github.com/bnksn/DiffEqSolver/blob/main/gallery/wavePlot.png)
![me](https://github.com/bnksn/DiffEqSolver/blob/main/gallery/waveAnim.gif)
