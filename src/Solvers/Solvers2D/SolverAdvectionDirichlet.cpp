#include "SolverAdvectionDirichlet.hpp"

#include <cmath>
#include <iostream>

SolverAdvectionDirichlet::SolverAdvectionDirichlet(
    const double xFinal, const int xNumSteps, const double yFinal,
    const int yNumSteps, const std::vector<double>& zInitial,
    const double velocity)
    : Solver2D(xFinal, xNumSteps, yFinal, yNumSteps, zInitial) {
    this->multiplier = velocity * this->dy / this->dx;
    if (this->multiplier > 1) {
        std::cout << "Warning. Numerical instability.\n";
    }
}

std::vector<double> SolverAdvectionDirichlet::Solve() const {
    auto zValues = std::vector<std::vector<double>>{zInitial};

    for (auto i = 0u; i < this->yNumSteps; ++i) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        // enforce dirichlet condition
        newPoints.front() = prevPoints.front();
        newPoints.back() = prevPoints.back();

        // Lax-Wendroff finite difference
        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] = 0.5 * (prevPoints[i + 1] + prevPoints[i - 1]) -
                           0.5 * this->multiplier *
                               (prevPoints[i + 1] - prevPoints[i - 1]);
        }

        zValues.push_back(newPoints);
    }

    return FlattenOutput(zValues);
}