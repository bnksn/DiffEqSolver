#pragma once

#include "Solver2D.hpp"

class SolverAdvectionDirichlet : public Solver2D {
   private:
    double multiplier;

   public:
    SolverAdvectionDirichlet(const double xFinal, const unsigned int xNumSteps,
                             const double yFinal, const unsigned int yNumSteps,
                             const std::vector<double>& zInitial,
                             const double velocity);

    std::vector<double> Solve() const override;
};