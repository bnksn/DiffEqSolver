#pragma once

#include "../solver.hpp"

class Solver1D : public Solver {
   protected:
    double xFinal;
    int xNumSteps;
    double dx;
    double yInitial;
    std::vector<double> coeffs;

    Solver1D(const double xFinal, const int xNumSteps, const double yInitial,
             const std::vector<double>& coeffs) noexcept;
};