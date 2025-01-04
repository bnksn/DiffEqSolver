#pragma once

#include <vector>
#include <math.h>

#include "../Coefficients.hpp"
#include "../Point.hpp"

class Solver
{
protected:
	Coeffs coeffs;
	double dt;
	int numSteps;

    Solver(const Coeffs coeffs, const double dt, const int numSteps) {
		this->coeffs = coeffs;
		this->dt = dt;
		this->numSteps = numSteps;
	}

public:
	const virtual std::vector<Point> Solve(const Point startingPoint) const = 0;
};