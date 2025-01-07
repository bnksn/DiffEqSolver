#include <iostream>
#include <memory>

#include "FunctionInputs.hpp"
#include "Solvers/CosineSolver.hpp"
#include "Solvers/PolynomialSolver.hpp"
#include "Solvers/SineSolver.hpp"
#include "UserInput.hpp"

std::unique_ptr<Solver> getSolver(const UserInput userInput) {
    switch (userInput.rhsFunc) {
        case FunctionInputs::Sine:
            return std::make_unique<SineSolver>(CoeffsTwo{1, 1}, userInput.dt,
                                                userInput.numSteps);
        case FunctionInputs::Cosine:
            return std::make_unique<CosineSolver>(CoeffsTwo{1, 1}, userInput.dt,
                                                  userInput.numSteps);
        case FunctionInputs::Polynomial:
            return std::make_unique<PolynomialSolver>(
                CoeffsFive{1, 0, 0, 0, 0}, userInput.dt, userInput.numSteps);
        default:
            throw std::invalid_argument("Invalid user input");
    }
}

UserInput simulateUserInput() {
    return {.rhsFunc = FunctionInputs::Sine, .dt = 0.1, .numSteps = 30};
}

int main() {
    const auto solver = getSolver(simulateUserInput());

    const auto& result = solver->Solve({.x = 0, .y = 0});

    for (const auto [x, y] : result) {
        std::cout << "x: " << x << " y: " << y << '\n';
    }
}