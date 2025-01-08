#pragma once

#include <vector>

class Solver2D {
   private:
    double xFinal;
    unsigned int xNumSteps;
    double dx;

    double yFinal;
    unsigned int yNumSteps;
    double dy;

    std::vector<int> coeffs;

   public:
    Solver2D(const double, const unsigned int, const double, const unsigned int,
             const std::vector<int>&);

    std::vector<std::vector<double>> HeatSolve(const std::vector<double>&,
                                               const double) const;
};