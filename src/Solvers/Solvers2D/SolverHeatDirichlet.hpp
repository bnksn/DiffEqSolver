#pragma once

#include "Solver2D.hpp"

class SolverHeatDirichlet : public Solver2D {
   private:
    double multiplier;

   public:
    SolverHeatDirichlet(const double xFinal, const int xNumSteps,
                        const double yFinal, const int yNumSteps,
                        const std::vector<double>& zInitial,
                        const double thermalDiffusivity);

    [[nodiscard]]
    std::vector<double> Solve() const override;
};