#include "SolverTrig.hpp"

#include <cmath>
#include <iostream>

SolverTrig::SolverTrig(const double xFinal, const unsigned int xNumSteps,
                       const double yInitial, const std::vector<double>& coeffs,
                       const TrigFunc trigFunc)
    : Solver1D(xFinal, xNumSteps, yInitial, coeffs) {
    this->trigFunc = trigFunc;
}

double SolverTrig::evaluateTrig(const int input) const {
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

std::vector<double> SolverTrig::Solve() const {
    auto yValues = std::vector{this->yInitial};

    for (auto stepsTaken = 0u; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew = yOld + this->dx * evaluateTrig(xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}
