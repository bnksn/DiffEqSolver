#pragma once

#include "../../Input/UserInputs.hpp"
#include "../Solver.hpp"

class Solver2D : public Solver {
   protected:
    double xFinal;
    int xNumSteps;
    double dx;
    double yFinal;
    int yNumSteps;
    double dy;
    std::vector<double> zInitial;
    BoundaryCondition boundaryCondition;

    [[nodiscard]]
    std::vector<double> flattenOutput(
        const std::vector<std::vector<double>>& output) const noexcept;

    void enforceBoundaryCondition(std::vector<double>& newPoints,
                                  const std::vector<double>& prevPoints) const;

    void warnNumericalUnstability() const noexcept;

   public:
    Solver2D(const double xFinal, const int xNumSteps, const double yFinal,
             const int yNumSteps, const std::vector<double>& zInitial,
             const BoundaryCondition boundaryCondition) noexcept;
};