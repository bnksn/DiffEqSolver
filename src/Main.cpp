#include <iostream>
#include <memory>

#include "Solvers/Solvers1D/SolverPolynomial.hpp"
#include "Solvers/Solvers1D/SolverTrig.hpp"
#include "Solvers/Solvers2D/SolverAdvection.hpp"
#include "Solvers/Solvers2D/SolverHeat.hpp"
#include "Solvers/Solvers2D/SolverWave.hpp"

enum class UserChoice { Polynomial, Trig, Heat, Advection, Wave };
enum class Dimension { Two, Three };

[[nodiscard]]
std::unique_ptr<Solver> GetSolver(const UserChoice choice,
                                  const TrigFunc trigFunc,
                                  const BoundaryCondition boundaryCondition,
                                  double xFinal, const int xNumSteps,
                                  const double yInitial, const double yFinal,
                                  const int yNumSteps,
                                  const std::vector<double>& zInitial) {
    switch (choice) {
        case (UserChoice::Polynomial):
            std::cout << "Polynomial\n";
            return std::make_unique<SolverPolynomial>(
                xFinal, xNumSteps, yInitial, std::vector{1.0, 1.0, 2.0});
        case (UserChoice::Trig):
            std::cout << "Trig\n";
            return std::make_unique<SolverTrig>(
                xFinal, xNumSteps, yInitial, std::vector{1.0, 1.0}, trigFunc);
        case (UserChoice::Heat):
            std::cout << "Heat\n";
            return std::make_unique<SolverHeat>(xFinal, xNumSteps, yFinal,
                                                yNumSteps, zInitial, 0.1,
                                                boundaryCondition);
        case (UserChoice::Advection):
            std::cout << "Advection\n";
            return std::make_unique<SolverAdvection>(xFinal, xNumSteps, yFinal,
                                                     yNumSteps, zInitial, 0.1,
                                                     boundaryCondition);
        case (UserChoice::Wave):
            std::cout << "Wave\n";
            return std::make_unique<SolverWave>(xFinal, xNumSteps, yFinal,
                                                yNumSteps, zInitial, 1,
                                                boundaryCondition);
        default:
            throw std::invalid_argument("invalid user input");
    }
}

int main() {
    // simulating user input
    const auto dimension = Dimension::Three;
    const auto choice = UserChoice::Wave;
    const auto trigFunc = TrigFunc::Cosine;
    const auto boundaryCondition = BoundaryCondition::Dirichlet;
    const auto xFinal = 1.0;
    const auto xNumSteps = 5;
    const auto yInitial = 1.0;
    const auto yFinal = 1.0;
    const auto yNumSteps = 100;
    const auto zInitial = {1.0, 2.0, 3.0, 2.0, 1.0};

    const auto solver =
        GetSolver(choice, trigFunc, boundaryCondition, xFinal, xNumSteps,
                  yInitial, yFinal, yNumSteps, zInitial);
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
        auto currIndex = 0;
        for (const auto num : result) {
            std::cout << num << ' ';
            if ((++currIndex) % xNumSteps == 0) {
                std::cout << '\n';
            }
        }
    }
}