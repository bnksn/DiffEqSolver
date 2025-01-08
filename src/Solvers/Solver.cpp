#include "Solver.hpp"

Solver::Solver(const double dt, const int numSteps,
               const std::vector<int>& coeffs) {
    this->dt = dt;
    this->numSteps = numSteps;
    this->coeffs = coeffs;
}

Solver::~Solver() {}

std::vector<Point> Solver::Solve(const Point startingPoint) const {
    auto result = std::vector{startingPoint};

    for (auto i = 0; i < numSteps; ++i) {
        const auto [oldT, oldF] = result.back();
        const auto newT = oldT + dt;
        const auto newF = oldF + dt * rhsFunction(oldT);

        result.push_back({newT, newF});
    }

    return result;
}