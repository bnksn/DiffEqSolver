#pragma once

#include <vector>

class Solver {
   protected:
    double xFinal;
    unsigned int xNumSteps;
    double dx;

    Solver(const double xFinal, const unsigned int xNumSteps);

   public:
    [[nodiscard]] std::vector<double> virtual Solve() const = 0;
};