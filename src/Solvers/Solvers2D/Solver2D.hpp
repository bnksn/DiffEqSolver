#pragma once

#include "../Solver.hpp"

class Solver2D : public Solver {
   protected:
    double yFinal;
    unsigned int yNumSteps;
    double dy;
    std::vector<double> zInitial;

    std::vector<double> FlattenOutput(
        const std::vector<std::vector<double>>& output) const;

   public:
    Solver2D(const double xFinal, const unsigned int xNumSteps,
             const double yFinal, const unsigned int yNumSteps,
             const std::vector<double>& zInitial);
};