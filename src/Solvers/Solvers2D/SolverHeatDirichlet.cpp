#include "SolverHeatDirichlet.hpp"

#include <cmath>
#include <iostream>

SolverHeatDirichlet::SolverHeatDirichlet(const double xFinal,
                                         const unsigned int xNumSteps,
                                         const double yFinal,
                                         const unsigned int yNumSteps,
                                         const std::vector<double>& zInitial,
                                         const double thermalDiffusivity)
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial) {
    this->multiplier = thermalDiffusivity * this->dy / (this->dx * this->dx);
    if (this->multiplier > 0.5) {
        std::cout << "Warning. Numerical instability.\n";
    }
}

std::vector<double> SolverHeatDirichlet::Solve() const {
    auto zValues = std::vector<std::vector<double>>{zInitial};

    for (auto i = 0u; i < this->yNumSteps; ++i) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        // enforce dirichlet condition
        newPoints.front() = prevPoints.front();
        newPoints.back() = prevPoints.back();

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