#pragma once

#include "Solver1D.hpp"

class SolverPolynomial : public Solver1D {
   private:
    double evaluatePolynomial(const int input) const;

   public:
    SolverPolynomial(const double xFinal, const unsigned int xNumSteps,
                     const double yInitial, const std::vector<double>& coeffs);

    std::vector<double> Solve() const override;
};