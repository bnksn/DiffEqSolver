#include "SolverHeat.hpp"

#include <cmath>
#include <iostream>

SolverHeat::SolverHeat(const double xFinal, const int xNumSteps,
                       const double yFinal, const int yNumSteps,
                       const std::vector<double>& zInitial,
                       const double thermalDiffusivity,
                       const BoundaryCondition boundaryCondition)
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial,
               boundaryCondition) {
    this->multiplier = thermalDiffusivity * this->dy / (this->dx * this->dx);
    if (this->multiplier > 0.5) {
        std::cout << "Warning. Numerical instability.\n";
    }
}

[[nodiscard]]
std::vector<double> SolverHeat::Solve() const {
    auto zValues = std::vector<std::vector<double>>{zInitial};

    for (auto i = 0; i < this->yNumSteps; ++i) {
        const auto prevPoints = zValues.back();
        auto newPoints = EnforceBoundaryCondition(prevPoints);

        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] =
                prevPoints[i] +
                this->multiplier *
                    (prevPoints[i + 1] + prevPoints[i - 1] - 2 * prevPoints[i]);
        }

        zValues.push_back(newPoints);
    }

    return FlattenOutput(zValues);
}