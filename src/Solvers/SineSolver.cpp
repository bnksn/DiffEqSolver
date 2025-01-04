#include "Solver.hpp"

class SineSolver : public Solver
{
public:
	SineSolver(const Coeffs coeffs, const double dt, const int numSteps) :
		Solver(coeffs, dt, numSteps) {}

	const std::vector<Point> Solve(const Point startingPoint) const override {
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
};