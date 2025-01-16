#pragma once

#include "../../input/userInputs.hpp"
#include "../solver.hpp"

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

    void warnNumericalInstability() const noexcept;

   public:
    Solver2D(const double xFinal, const int xNumSteps, const double yFinal,
             const int yNumSteps, const std::vector<double>& zInitial,
             const BoundaryCondition boundaryCondition) noexcept;
};