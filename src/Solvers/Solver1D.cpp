#include "Solver1D.hpp"

#include <cmath>

Solver1D::Solver1D(const double xFinal, const unsigned int xNumSteps)
    : Solver(xFinal, xNumSteps) {}

std::vector<double> Solver1D::SineSolve(
    const double yInitial, const std::vector<double>& coeffs) const {
    auto yValues = std::vector<double>(xNumSteps + 1);
    yValues.push_back(yInitial);

    for (auto stepsTaken = 0; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew =
            yOld + this->dx * coeffs[0] * std::sin(coeffs[1] * xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}

std::vector<double> Solver1D::PolynomialSolve(
    const double yInitial, const std::vector<double>& coeffs) const {
    auto yValues = std::vector<double>(xNumSteps + 1);
    yValues.push_back(yInitial);

    const auto evalPolynomial = [&coeffs](const double input) {
        auto result = 0;

        auto currPower = 0;
        for (const auto coeff : coeffs) {
            result += coeff * std::pow(input, currPower++);
        }

        return result;
    };

    for (auto stepsTaken = 0; stepsTaken < this->xNumSteps; ++stepsTaken) {
        const auto xCurr = stepsTaken * this->dx;
        const auto yOld = yValues.back();
        const auto yNew = yOld + this->dx * evalPolynomial(xCurr);

        yValues.push_back(yNew);
    }

    return yValues;
}