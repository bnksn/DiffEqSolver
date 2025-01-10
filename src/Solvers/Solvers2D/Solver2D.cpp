#include "Solver2D.hpp"

#include <cmath>

Solver2D::Solver2D(const double xFinal, const int xNumSteps,
                   const double yFinal, const int yNumSteps,
                   const std::vector<double>& zInitial)
    : Solver(xFinal, xNumSteps) {
    this->yFinal = yFinal;
    this->yNumSteps = yNumSteps;
    this->dy = yFinal / yNumSteps;
    this->zInitial = zInitial;
}

[[nodiscard]]
std::vector<double> Solver2D::FlattenOutput(
    const std::vector<std::vector<double>>& output) const {
    auto flatOutput = std::vector<double>();

    for (const auto& vec : output) {
        flatOutput.insert(flatOutput.end(), vec.begin(), vec.end());
    }

    return flatOutput;
}
