#pragma once

#include "Solver1D.hpp"

class SolverSine : public Solver1D {
   public:
    SolverSine(const double xFinal, const unsigned int xNumSteps,
               const double yInitial, const std::vector<double>& coeffs);

    std::vector<double> Solve() const;
};