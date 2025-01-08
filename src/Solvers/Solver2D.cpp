#include "Solver2D.hpp"

#include <cmath>

Solver2D::Solver2D(const double xFinal, const unsigned int xNumSteps,
                   const double yFinal, const unsigned int yNumSteps,
                   const std::vector<int>& coeffs) {
    this->xFinal = xFinal;
    this->xNumSteps = xNumSteps;
    this->dx = xFinal / xNumSteps;

    this->yFinal = yFinal;
    this->yNumSteps = yNumSteps;
    this->dy = yFinal / yNumSteps;

    this->coeffs = coeffs;
}

std::vector<std::vector<double>> Solver2D::HeatSolve(
    const std::vector<double>& initialValues, const double alpha) const {
    if (this->xNumSteps <= 1) {
        return std::vector<std::vector<double>>(this->yNumSteps + 1,
                                                initialValues);
    }

    auto result = std::vector<std::vector<double>>{initialValues};
    for (auto i = 0; i < this->yNumSteps; ++i) {
        const auto prevPoints = result.back();
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

    return result;
}