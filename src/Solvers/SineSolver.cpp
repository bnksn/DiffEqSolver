#include "SineSolver.hpp"

SineSolver::SineSolver(const Coeffs coeffs, const double dt, const int numSteps) :
		Solver(coeffs, dt, numSteps) {}

const std::vector<Point>SineSolver::Solve(const Point startingPoint) const {
	auto result = std::vector{startingPoint};

	for (auto i = 0; i < numSteps; ++i)
	{
		const auto [oldT, oldF] = result.back();
		const auto newT = oldT + dt;
		const auto newF = oldF + dt * (coeffs.A * std::sin(coeffs.B * oldT));

		result.push_back({newT, newF});
	}

	return result;
}