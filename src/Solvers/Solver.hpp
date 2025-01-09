#pragma once

#include <vector>

class Solver {
   protected:
    double xFinal;
    unsigned int xNumSteps;
    double dx;

   public:
    Solver(const double xFinal, const unsigned int xNumSteps);
};