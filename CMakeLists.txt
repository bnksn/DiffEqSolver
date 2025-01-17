cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_CLANG_TIDY 
    clang-tidy;
        -checks=cppcoreguidelines-*,-cppcoreguidelines-avoid-magic-numbers,-cppcoreguidelines-non-private-member-variables-in-classes,modernize-*,-modernize-use-trailing-return-type,bugprone-*,-bugprone-easily-swappable-parameters;
        -warnings-as-errors=*;
        -header-filter=.*;)

project(DiffEqSolver)

enable_testing()

find_package(GTest REQUIRED)

add_library(DiffEqSolverLib
    STATIC 
    src/solvers/solvers1D/solver1D.cpp 
    src/solvers/solvers1D/solverPolynomial.cpp 
    src/solvers/solvers1D/solverTrig.cpp 
    src/solvers/solvers2D/solver2D.cpp 
    src/solvers/solvers2D/solverHeat.cpp 
    src/solvers/solvers2D/solverAdvection.cpp 
    src/solvers/solvers2D/solverWave.cpp 
)

add_executable(DiffEqSolver
    src/main.cpp 
)

target_link_libraries(DiffEqSolver PRIVATE DiffEqSolverLib) 

add_executable(DiffEqSolverTests 
    tests/main.cpp 
    tests/input/configReaderTests.cpp 
    tests/output/resultWriterTests.cpp 
    tests/solvers/solvers1D/solverTrigTests.cpp 
    tests/solvers/solvers2D/solverHeatTests.cpp 
)

target_link_libraries(DiffEqSolverTests PRIVATE GTest::gtest DiffEqSolverLib) 

add_test(NAME DiffEqSolverTests
         COMMAND $<TARGET_FILE:DiffEqSolverTests>)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -O3)
endif()