#include <iostream>
#include <memory>

#include "Solvers/CosineSolver.hpp"
#include "Solvers/PolynomialSolver.hpp"
#include "Solvers/SineSolver.hpp"

enum class FuntionInputs { Sine, Cosine, Polynomial };

std::unique_ptr<Solver> getSolver(const FuntionInputs functionInput,
                                  const double dtInput,
                                  const int numStepsInput) {
    switch (functionInput) {
        case FuntionInputs::Sine:
            return std::make_unique<SineSolver>(CoeffsTwo{1, 1}, dtInput,
                                                numStepsInput);
        case FuntionInputs::Cosine:
            return std::make_unique<CosineSolver>(CoeffsTwo{1, 1}, dtInput,
                                                  numStepsInput);
        case FuntionInputs::Polynomial:
            return std::make_unique<PolynomialSolver>(CoeffsFive{1, 0, 0, 0, 0},
                                                      dtInput, numStepsInput);
        default:
            throw std::invalid_argument("Invalid function input");
    }
}

int main() {
    // Simulate user input
    const auto functionInput = FuntionInputs::Cosine;
    const auto dtInput = 0.1;
    const auto numStepsInput = 30;

    const auto solver = getSolver(functionInput, dtInput, numStepsInput);

    const auto& result = solver->Solve({.x = 0, .y = 0});

    for (const auto [x, y] : result) {
        std::cout << "x: " << x << " y: " << y << '\n';
    }
}