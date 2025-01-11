#pragma once

#include "../../Math/BoundaryCondition.hpp"
#include "../Solver.hpp"

class Solver2D : public Solver {
   protected:
    double yFinal;
    int yNumSteps;
    double dy;
    std::vector<double> zInitial;
    BoundaryCondition boundaryCondition;

    [[nodiscard]]
    std::vector<double> FlattenOutput(
        const std::vector<std::vector<double>>& output) const noexcept;

    void EnforceBoundaryCondition(std::vector<double>& newPoints,
                                  const std::vector<double>& prevPoints) const;

    void WarnNumericalUnstability() const noexcept;

   public:
    Solver2D(const double xFinal, const int xNumSteps, const double yFinal,
             const int yNumSteps, const std::vector<double>& zInitial,
             const BoundaryCondition boundaryCondition) noexcept;
};