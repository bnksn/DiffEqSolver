#pragma once

#include <vector>

class Solver {
   protected:
    double xFinal;
    int xNumSteps;
    double dx;

    Solver(const double xFinal, const int xNumSteps) noexcept;

   public:
    [[nodiscard]] std::vector<double> virtual solve() const = 0;
};