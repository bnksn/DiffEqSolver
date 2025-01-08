#include <iostream>
#include <memory>

#include "Solvers/Solver1D.hpp"

int main() {
    // get user input
    const auto xFinal = 10;
    const auto xNumSteps = 10;
    const auto yFinal = 10;
    const auto yNumSteps = 10;
    const auto yInitial = 1;
    const auto coeffs = std::vector{1.0, 1.0};

    const auto solver = Solver1D(xFinal, xNumSteps);

    const auto& result = solver.SineSolve(yInitial, coeffs);

    for (const auto num : result) {
        std::cout << num << '\n';
    }
}