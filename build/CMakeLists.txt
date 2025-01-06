cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DiffEqSolver)

set(SOURCES
    ../src/main.cpp
    ../src/Solvers/Solver.cpp
    ../src/Solvers/CosineSolver.cpp
    ../src/Solvers/SineSolver.cpp
    ../src/Solvers/PolynomialSolver.cpp
)

add_executable(DiffEqSolver ${SOURCES})

target_compile_options(DiffEqSolver PRIVATE 
    -Werror
    -Wall 
    -Wextra 
    -Wpedantic 
    -Wconversion 
    -O3
)