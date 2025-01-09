cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DiffEqSolver)

add_executable(DiffEqSolver 
  ../src/Main.cpp
  ../src/Solvers/Solver.cpp
  ../src/Solvers/Solver1D.cpp
  ../src/Solvers/Solver2D.cpp
)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -O3)
endif()