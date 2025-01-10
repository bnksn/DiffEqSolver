#pragma once

#include <vector>

class Solver {
   protected:
    double xFinal;
    int xNumSteps;
    double dx;

    Solver(const double xFinal, const int xNumSteps);

   public:
    [[nodiscard]] std::vector<double> virtual Solve() const = 0;
};