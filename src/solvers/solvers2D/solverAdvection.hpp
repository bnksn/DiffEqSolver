#pragma once

#include "solver2D.hpp"

class SolverAdvection final : public Solver2D {
   private:
    double multiplier;

   public:
    SolverAdvection(const double xFinal, const int xNumSteps, const double yFinal,
                    const int yNumSteps, const std::vector<double>& zInitial, const double velocity,
                    const BoundaryCondition boundaryCondition) noexcept;

    [[nodiscard]]
    std::vector<double> solve() const final;
};