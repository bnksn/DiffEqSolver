#include "SolverSine.hpp"

#include <cmath>

SolverSine::SolverSine(const double xFinal, const unsigned int xNumSteps,
                       const double yInitial, const std::vector<double>& coeffs)
    : Solver1D(xFinal, xNumSteps, yInitial, coeffs) {}

std::vector<double> SolverSine::Solve() const {
    auto yValues = std::vector{this->yInitial};

    for (auto stepsTaken = 0u; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew = yOld + this->dx * this->coeffs[0] *
                                     std::sin(this->coeffs[1] * xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}
