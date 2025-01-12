#include <iostream>
#include <memory>

#include "Output/ResultWriter.hpp"
#include "Solvers/Solvers1D/SolverPolynomial.hpp"
#include "Solvers/Solvers1D/SolverTrig.hpp"
#include "Solvers/Solvers2D/SolverAdvection.hpp"
#include "Solvers/Solvers2D/SolverHeat.hpp"
#include "Solvers/Solvers2D/SolverWave.hpp"

enum class UserChoice { Polynomial, Trig, Heat, Advection, Wave };

[[nodiscard]]
std::unique_ptr<Solver> getSolver(const UserChoice choice,
                                  const TrigFunc trigFunc,
                                  const BoundaryCondition boundaryCondition,
                                  const double xFinal, const int xNumSteps,
                                  const double yInitial, const double yFinal,
                                  const int yNumSteps,
                                  const std::vector<double>& zInitial) {
    switch (choice) {
        case (UserChoice::Polynomial):
            return std::make_unique<SolverPolynomial>(
                xFinal, xNumSteps, yInitial, std::vector{1.0, 1.0, 2.0});
        case (UserChoice::Trig):
            return std::make_unique<SolverTrig>(
                xFinal, xNumSteps, yInitial, std::vector{1.0, 1.0}, trigFunc);
        case (UserChoice::Heat):
            return std::make_unique<SolverHeat>(xFinal, xNumSteps, yFinal,
                                                yNumSteps, zInitial, 0.1,
                                                boundaryCondition);
        case (UserChoice::Advection):
            return std::make_unique<SolverAdvection>(xFinal, xNumSteps, yFinal,
                                                     yNumSteps, zInitial, 0.1,
                                                     boundaryCondition);
        case (UserChoice::Wave):
            return std::make_unique<SolverWave>(xFinal, xNumSteps, yFinal,
                                                yNumSteps, zInitial, 0.1,
                                                boundaryCondition);
        default:
            throw std::invalid_argument("Invalid user input");
    }
}

int main() {
    // simulating user input
    const auto resultPath = "data.txt";
    const auto dimension = 3;
    const auto choice = UserChoice::Wave;
    const auto trigFunc = TrigFunc::Cosine;
    const auto boundaryCondition = BoundaryCondition::Dirichlet;

    const auto xFinal = 1;
    const auto xNumSteps = 20;

    // 1d solver only
    const auto yInitial = 2;

    // 2d solver only
    const auto zInitial = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.5,
                           1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6,
                           1.5, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0};
    const auto yFinal = 2.0;
    const auto yNumSteps = 200;

    const auto solver =
        getSolver(choice, trigFunc, boundaryCondition, xFinal, xNumSteps,
                  yInitial, yFinal, yNumSteps, zInitial);
    const auto& results = solver->solve();

    const auto resultWriter = ResultWriter(results, resultPath);
    switch (dimension) {
        case (2):
            resultWriter.write2d(xNumSteps, xFinal);
            break;
        case (3):
            resultWriter.write3d(xNumSteps, xFinal, yNumSteps, yFinal);
            break;
        default:
            throw std::invalid_argument("Dimension not valid");
    }
}