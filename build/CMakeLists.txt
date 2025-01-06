cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(DiffEqSolver)

set(SOURCES
    ../src/main.cpp
    ../src/Solvers/Solver.cpp
    ../src/Solvers/CosineSolver.cpp
    ../src/Solvers/SineSolver.cpp
    ../src/Solvers/PolynomialSolver.cpp
)

# add the executable
add_executable(DiffEqSolver ${SOURCES})
