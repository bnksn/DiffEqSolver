#include "Solver.hpp"

Solver::Solver(const Coeffs coeffs, const double dt, const int numSteps) {
    this->coeffs = coeffs;
    this->dt = dt;
    this->numSteps = numSteps;
}

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