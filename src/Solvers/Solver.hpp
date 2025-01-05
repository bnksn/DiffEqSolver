#pragma once

#include <math.h>

#include <vector>

#include "../Coefficients.hpp"
#include "../Point.hpp"

class Solver {
   private:
    double virtual rhsFunction(const double t) const = 0;

   protected:
    Coeffs coeffs;
    double dt;
    int numSteps;

    Solver(const Coeffs coeffs, const double dt, const int numSteps);

   public:
    std::vector<Point> Solve(const Point startingPoint) const;
};