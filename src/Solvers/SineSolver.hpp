#pragma once

#include "Solver.hpp"

class SineSolver : public Solver
{
public:
	SineSolver(const Coeffs coeffs, const double dt, const int numSteps);

	const std::vector<Point> Solve(const Point startingPoint) const override;
};