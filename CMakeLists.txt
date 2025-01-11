cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DiffEqSolver)

add_executable(DiffEqSolver 
  ../src/Main.cpp
  ../src/Solvers/Solver.cpp
  ../src/Solvers/Solvers1D/Solver1D.cpp
  ../src/Solvers/Solvers1D/SolverPolynomial.cpp
  ../src/Solvers/Solvers1D/SolverTrig.cpp
  ../src/Solvers/Solvers2D/Solver2D.cpp
  ../src/Solvers/Solvers2D/SolverHeat.cpp
  ../src/Solvers/Solvers2D/SolverAdvection.cpp
  ../src/Solvers/Solvers2D/SolverWave.cpp
  ../src/Output/ResultWriter.cpp
)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -O3)
endif()