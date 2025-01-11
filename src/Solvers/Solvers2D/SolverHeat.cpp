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
        WarnNumericalUnstability();
    }
}

[[nodiscard]]
std::vector<double> SolverHeat::Solve() const {
    auto zValues = std::vector<std::vector<double>>{this->zInitial};

    for (auto step = 0; step < this->yNumSteps; ++step) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] =
                prevPoints[i] +
                this->multiplier *
                    (prevPoints[i + 1] + prevPoints[i - 1] - 2 * prevPoints[i]);
        }

        EnforceBoundaryCondition(newPoints, prevPoints);

        zValues.push_back(newPoints);
    }

    return FlattenOutput(zValues);
}