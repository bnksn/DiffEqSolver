#pragma once

#include <math.h>

#include <vector>

#include "../Coefficients.hpp"
#include "../Point.hpp"

class Solver {
   protected:
    Coeffs coeffs;
    double dt;
    int numSteps;

    Solver(const Coeffs coeffs, const double dt, const int numSteps);

   public:
    virtual std::vector<Point> Solve(const Point startingPoint) const = 0;
};