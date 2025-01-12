#include "SolverAdvection.hpp"

#include <cmath>
#include <iostream>

SolverAdvection::SolverAdvection(
    const double xFinal, const int xNumSteps, const double yFinal,
    const int yNumSteps, const std::vector<double>& zInitial,
    const double velocity, const BoundaryCondition boundaryCondition) noexcept
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial,
               boundaryCondition) {
    this->multiplier = velocity * this->dy / this->dx;
    if (this->multiplier > 1) {
        warnNumericalInstability();
    }
}

[[nodiscard]]
std::vector<double> SolverAdvection::solve() const {
    auto zValues = std::vector<std::vector<double>>{this->zInitial};

    for (auto step = 0; step < this->yNumSteps; ++step) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] = 0.5 * (prevPoints[i + 1] + prevPoints[i - 1]) -
                           0.5 * this->multiplier *
                               (prevPoints[i + 1] - prevPoints[i - 1]);
        }

        enforceBoundaryCondition(newPoints, prevPoints);

        zValues.push_back(newPoints);
    }

    return flattenOutput(zValues);
}