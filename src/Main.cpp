#include <iostream>
#include <memory>

#include "Input/FunctionInputs.hpp"
#include "Input/UserInput.hpp"
#include "Solvers/CosineSolver.hpp"
#include "Solvers/PolynomialSolver.hpp"
#include "Solvers/SineSolver.hpp"

std::unique_ptr<Solver> getSolver(const FunctionInputs rhsFunc,
                                  const std::vector<int>& coeffs,
                                  const double dt,
                                  const unsigned int numSteps) {
    switch (rhsFunc) {
        case FunctionInputs::Sine:
            return std::make_unique<SineSolver>(dt, numSteps, coeffs);
        case FunctionInputs::Cosine:
            return std::make_unique<CosineSolver>(dt, numSteps, coeffs);
        case FunctionInputs::Polynomial:
            return std::make_unique<PolynomialSolver>(dt, numSteps, coeffs);
        default:
            throw std::invalid_argument("Invalid user input");
    }
}

UserInput simulateUserInput() {
    return {.rhsFunc = FunctionInputs::Sine,
            .coeffs = std::vector{1, 1},
            .dt = 0.1,
            .numSteps = 30,
            .initialValue = {.x = 0, .y = 0}};
}

int main() {
    const auto [rhsFunc, coeffs, dt, numSteps, initialValue] =
        simulateUserInput();
    const auto solver = getSolver(rhsFunc, coeffs, dt, numSteps);

    const auto& result = solver->Solve(initialValue);

    for (const auto [x, y] : result) {
        std::cout << "x: " << x << " y: " << y << '\n';
    }
}