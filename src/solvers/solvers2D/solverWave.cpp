#include "solverWave.hpp"

#include <cmath>
#include <iostream>

SolverWave::SolverWave(const double xFinal, const int xNumSteps,
                       const double yFinal, const int yNumSteps,
                       const std::vector<double>& zInitial,
                       const double waveSpeed,
                       const BoundaryCondition boundaryCondition) noexcept
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial,
               boundaryCondition),
      multiplier(std::pow(waveSpeed * this->dy / (this->dx * this->dx), 2)) {
    if (this->multiplier > 1) {
        warnNumericalInstability();
    }
}

[[nodiscard]]
std::vector<double> SolverWave::solve() const {
    // Assuming initial velocity is 0
    // First and second displacements match
    auto zValues =
        std::vector<std::vector<double>>{this->zInitial, this->zInitial};

    for (auto step = 1; step < this->yNumSteps; ++step) {
        const auto& prevPoints = zValues[zValues.size() - 1];
        const auto& prevPrevPoints = zValues[zValues.size() - 2];

        auto newPoints = std::vector<double>(prevPoints.size());

        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] =
                2 * prevPoints[i] - prevPrevPoints[i] +
                this->multiplier *
                    (prevPoints[i + 1] - 2 * prevPoints[i] + prevPoints[i - 1]);
        }

        enforceBoundaryCondition(newPoints, prevPoints);

        zValues.push_back(newPoints);
    }

    return flattenOutput(zValues);
}