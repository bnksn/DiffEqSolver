#pragma once

#include "solver1D.hpp"

class SolverPolynomial final : public Solver1D {
   private:
    [[nodiscard]]
    double evaluatePolynomial(const double input) const noexcept;

   public:
    SolverPolynomial(const double xFinal, const int xNumSteps,
                     const double yInitial,
                     const std::vector<double>& coeffs) noexcept;

    [[nodiscard]]
    std::vector<double> solve() const override final;
};