#pragma once

#include "../Solver.hpp"

class Solver2D : public Solver {
   protected:
    double yFinal;
    int yNumSteps;
    double dy;
    std::vector<double> zInitial;

    [[nodiscard]]
    std::vector<double> FlattenOutput(
        const std::vector<std::vector<double>>& output) const;

   public:
    Solver2D(const double xFinal, const int xNumSteps, const double yFinal,
             const int yNumSteps, const std::vector<double>& zInitial);
};