#pragma once

#include "Solver2D.hpp"

class SolverHeatDirichlet : public Solver2D {
   private:
    double multiplier;

   public:
    SolverHeatDirichlet(const double xFinal, const unsigned int xNumSteps,
                        const double yFinal, const unsigned int yNumSteps,
                        const std::vector<double>& zInitial,
                        const double thermalDiffusivity);

    std::vector<double> Solve() const;
};