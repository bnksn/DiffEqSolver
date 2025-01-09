#pragma once

#include <vector>

#include "Solver.hpp"

class Solver2D : Solver {
   protected:
    double yFinal;
    unsigned int yNumSteps;
    double dy;

   public:
    Solver2D(const double xFinal, const unsigned int xNumSteps,
             const double yFinal, const unsigned int yNumSteps,
             const std::vector<int>& coeffs);

    std::vector<double> HeatSolve(const std::vector<double>& initialValues,
                                  const double alpha) const;

    std::vector<double> flattenOutput(
        const std::vector<std::vector<double>>& output) const;
};