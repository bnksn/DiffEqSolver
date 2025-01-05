#include <iostream>
#include <memory>

#include "Solvers/CosineSolver.hpp"
#include "Solvers/PolynomialSolver.hpp"
#include "Solvers/SineSolver.hpp"

std::unique_ptr<Solver> getSolver() {
    return std::make_unique<PolynomialSolver>(CoeffsFive{1, 0, 0, 0, 0}, 0.1,
                                              30);
}

int main() {
    const auto solver = getSolver();

    const auto& result = solver->Solve({.x = 0, .y = 0});

    for (const auto [x, y] : result) {
        std::cout << "x: " << x << " y: " << y << '\n';
    }
}