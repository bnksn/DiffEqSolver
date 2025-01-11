#pragma once

#include "../../Math/BoundaryCondition.hpp"
#include "Solver2D.hpp"

class SolverAdvection : public Solver2D {
   private:
    double multiplier;

   public:
    SolverAdvection(const double xFinal, const int xNumSteps,
                    const double yFinal, const int yNumSteps,
                    const std::vector<double>& zInitial, const double velocity,
                    const BoundaryCondition boundaryCondition) noexcept;

    [[nodiscard]]
    std::vector<double> Solve() const override;
};