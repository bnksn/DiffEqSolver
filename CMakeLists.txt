cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DiffEqSolver)

enable_testing()

find_package(GTest REQUIRED)

add_library(DiffEqSolverLib
    STATIC 
    ../src/Solvers/Solver.cpp 
    ../src/Solvers/Solvers1D/Solver1D.cpp 
    ../src/Solvers/Solvers1D/SolverPolynomial.cpp 
    ../src/Solvers/Solvers1D/SolverTrig.cpp 
    ../src/Solvers/Solvers2D/Solver2D.cpp 
    ../src/Solvers/Solvers2D/SolverHeat.cpp 
    ../src/Solvers/Solvers2D/SolverAdvection.cpp 
    ../src/Solvers/Solvers2D/SolverWave.cpp 
)

add_executable(DiffEqSolver
    ../src/Main.cpp 
)

target_link_libraries(DiffEqSolver PRIVATE DiffEqSolverLib) 

add_executable(DiffEqSolverTests 
    ../tests/Main.cpp 
    ../tests/Input/ConfigReaderTests.cpp 
    ../tests/Output/ResultWriterTests.cpp 
    ../tests/Solvers/Solvers1D/SolverTrigTests.cpp 
    ../tests/Solvers/Solvers2D/SolverHeatTests.cpp 
)

target_link_libraries(DiffEqSolverTests PRIVATE GTest::gtest DiffEqSolverLib) 

add_test(NAME DiffEqSolverTests
         COMMAND $<TARGET_FILE:DiffEqSolverTests>)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -O3)
endif()