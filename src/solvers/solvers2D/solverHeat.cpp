#include "solverHeat.hpp"

#include <cmath>
#include <iostream>

SolverHeat::SolverHeat(const double xFinal, const int xNumSteps, const double yFinal,
                       const int yNumSteps, const std::vector<double>& zInitial,
                       const double thermalDiffusivity,
                       const BoundaryCondition boundaryCondition) noexcept
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial, boundaryCondition),
      multiplier(thermalDiffusivity * this->dy / (this->dx * this->dx)) {
    if (this->multiplier > 0.5) {
        warnNumericalInstability();
    }
}

[[nodiscard]]
std::vector<double> SolverHeat::solve() const {
    auto zValues = std::vector<std::vector<double>>{this->zInitial};

    for (auto step = 0; step < this->yNumSteps; ++step) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] =
                prevPoints[i] +
                this->multiplier * (prevPoints[i + 1] + prevPoints[i - 1] - 2 * prevPoints[i]);
        }

        enforceBoundaryCondition(newPoints, prevPoints);

        zValues.push_back(newPoints);
    }

    return flattenOutput(zValues);
}