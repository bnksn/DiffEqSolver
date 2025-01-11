#include "Solver2D.hpp"

#include <cmath>
#include <iostream>

Solver2D::Solver2D(const double xFinal, const int xNumSteps,
                   const double yFinal, const int yNumSteps,
                   const std::vector<double>& zInitial,
                   const BoundaryCondition boundaryCondition) noexcept
    : Solver(xFinal, xNumSteps) {
    this->yFinal = yFinal;
    this->yNumSteps = yNumSteps;
    this->dy = yFinal / yNumSteps;
    this->zInitial = zInitial;
    this->boundaryCondition = boundaryCondition;
}

[[nodiscard]]
std::vector<double> Solver2D::flattenOutput(
    const std::vector<std::vector<double>>& output) const noexcept {
    auto flatOutput = std::vector<double>();

    for (const auto& vec : output) {
        flatOutput.insert(flatOutput.end(), vec.begin(), vec.end());
    }

    return flatOutput;
}

void Solver2D::enforceBoundaryCondition(
    std::vector<double>& newPoints,
    const std::vector<double>& prevPoints) const {
    if (this->boundaryCondition == BoundaryCondition::Dirichlet) {
        newPoints.front() = prevPoints.front();
        newPoints.back() = prevPoints.back();
    } else if (this->boundaryCondition == BoundaryCondition::Neumann) {
        newPoints.front() = newPoints[1];
        newPoints.back() = newPoints[newPoints.size() - 2];
    } else {
        throw std::invalid_argument("Boundary condition not recognised");
    }
}

void Solver2D::warnNumericalUnstability() const noexcept {
    std::cout << "Warning. Numerical instability.\n";
}
