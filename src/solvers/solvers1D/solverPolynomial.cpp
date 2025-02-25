#include "solverPolynomial.hpp"

#include <cmath>

SolverPolynomial::SolverPolynomial(const double xFinal, const int xNumSteps, const double yInitial,
                                   const std::vector<double>& coeffs) noexcept
    : Solver1D(xFinal, xNumSteps, yInitial, coeffs) {}

[[nodiscard]]
double SolverPolynomial::evaluatePolynomial(const double input) const noexcept {
    auto result = 0.0;

    auto currPower = 0;
    for (const auto coeff : this->coeffs) {
        result += coeff * std::pow(input, currPower++);
    }

    return result;
}

[[nodiscard]]
std::vector<double> SolverPolynomial::solve() const {
    auto yValues = std::vector{this->yInitial};

    for (auto stepsTaken = 0; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew = yOld + this->dx * evaluatePolynomial(xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}