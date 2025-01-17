#include "solverTrig.hpp"

#include <cmath>
#include <iostream>

SolverTrig::SolverTrig(const double xFinal, const int xNumSteps,
                       const double yInitial, const std::vector<double>& coeffs,
                       const TrigFunc trigFunc) noexcept
    : Solver1D(xFinal, xNumSteps, yInitial, coeffs), trigFunc(trigFunc) {}

[[nodiscard]]
double SolverTrig::evaluateTrig(const double input) const {
    switch (this->trigFunc) {
        case (TrigFunc::Sine):
            return this->coeffs[0] * std::sin(this->coeffs[1] * input);
        case (TrigFunc::Cosine):
            return this->coeffs[0] * std::cos(this->coeffs[1] * input);
        case (TrigFunc::Tangent):
            return this->coeffs[0] * std::tan(this->coeffs[1] * input);
        default:
            throw std::invalid_argument("Trig function not recognised");
    }
}

[[nodiscard]]
std::vector<double> SolverTrig::solve() const {
    auto yValues = std::vector{this->yInitial};

    for (auto stepsTaken = 0; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew = yOld + this->dx * evaluateTrig(xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}
