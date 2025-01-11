#include "Solver.hpp"

Solver::Solver(const double xFinal, const int xNumSteps) noexcept {
    this->xFinal = xFinal;
    this->xNumSteps = xNumSteps;
    this->dx = xFinal / xNumSteps;
}