#include "Solver2D.hpp"

#include <cmath>

Solver2D::Solver2D(const double xFinal, const unsigned int xNumSteps,
                   const double yFinal, const unsigned int yNumSteps,
                   const std::vector<int>& coeffs)
    : Solver(xFinal, xNumSteps) {
    this->yFinal = yFinal;
    this->yNumSteps = yNumSteps;
    this->dy = yFinal / yNumSteps;
}

std::vector<double> Solver2D::flattenOutput(
    const std::vector<std::vector<double>>& output) const {
    auto flatOutput = std::vector<double>();
    for (const auto& vec : output) {
        flatOutput.insert(flatOutput.end(), vec.begin(), vec.end());
    }
    return flatOutput;
}

std::vector<double> Solver2D::HeatSolve(const std::vector<double>& zInitial,
                                        const double alpha) const {
    if (this->xNumSteps <= 1) {
        return flattenOutput(std::vector(this->yNumSteps + 1, zInitial));
    }

    auto zValues = std::vector<std::vector<double>>{zInitial};
    for (auto i = 0; i < this->yNumSteps; ++i) {
        const auto prevPoints = zValues.back();
        auto newPoints = std::vector<double>(prevPoints.size());

        // enforce dirichlet condition
        newPoints.front() = prevPoints.front();
        newPoints.back() = prevPoints.back();

        const auto multiplier = alpha * this->dy / (this->dx * this->dx);
        for (auto i = 1; i < prevPoints.size() - 1; ++i) {
            newPoints[i] =
                prevPoints[i] + alpha * (prevPoints[i + 1] + prevPoints[i - 1] -
                                         2 * prevPoints[i]);
        }
    }

    return flattenOutput(zValues);
}
