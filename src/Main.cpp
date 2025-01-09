#include <iostream>
#include <memory>

#include "Solvers/Solvers1D/SolverPolynomial.hpp"
#include "Solvers/Solvers1D/SolverSine.hpp"
#include "Solvers/Solvers2D/SolverHeatDirichlet.hpp"

enum class UserChoice { Polynomial, Sine, Heat };
enum class Dimension { Two, Three };

std::unique_ptr<Solver> GetSolver(const UserChoice choice, const double xFinal,
                                  const unsigned int xNumSteps,
                                  const double yInitial, const double yFinal,
                                  const unsigned int yNumSteps,
                                  const std::vector<double>& zInitial) {
    switch (choice) {
        case (UserChoice::Polynomial):
            std::cout << "Polynomial\n";
            return std::make_unique<SolverPolynomial>(
                xFinal, xNumSteps, yInitial, std::vector{1.0, 1.0, 2.0});
        case (UserChoice::Sine):
            std::cout << "Sine\n";
            return std::make_unique<SolverSine>(xFinal, xNumSteps, yInitial,
                                                std::vector{1.0, 1.0});
        case (UserChoice::Heat):
            std::cout << "Heat\n";
            return std::make_unique<SolverHeatDirichlet>(
                xFinal, xNumSteps, yFinal, yNumSteps, zInitial, 0.1);
        default:
            throw std::invalid_argument("invalid user input");
    }
}

int main() {
    // simulating user input
    const auto dimension = Dimension::Three;
    const auto choice = UserChoice::Heat;
    const auto xFinal = 1.0;
    const auto xNumSteps = 5u;
    const auto yInitial = 1.0;
    const auto yFinal = 1.0;
    const auto yNumSteps = 100u;
    const auto zInitial = {1.0, 2.0, 3.0, 2.0, 1.0};

    const auto solver = GetSolver(choice, xFinal, xNumSteps, yInitial, yFinal,
                                  yNumSteps, zInitial);
    const auto& result = solver->Solve();

    // simulating 2D plot
    if (dimension == Dimension::Two) {
        for (const auto num : result) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    // simulating 3D plot
    if (dimension == Dimension::Three) {
        auto currIndex = 0u;
        for (const auto num : result) {
            std::cout << num << ' ';
            if ((++currIndex) % xNumSteps == 0) {
                std::cout << '\n';
            }
        }
    }
}