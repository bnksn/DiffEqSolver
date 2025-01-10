#pragma once

#include "Solver2D.hpp"

class SolverAdvectionDirichlet : public Solver2D {
   private:
    double multiplier;

   public:
    SolverAdvectionDirichlet(const double xFinal, const int xNumSteps,
                             const double yFinal, const int yNumSteps,
                             const std::vector<double>& zInitial,
                             const double velocity);

    [[nodiscard]]
    std::vector<double> Solve() const override;
};