#pragma once

#include <math.h>

#include <vector>

#include "../Coefficients.hpp"
#include "../Point.hpp"

class Solver {
   private:
    double virtual rhsFunction(const double t) const = 0;

   protected:
    double dt;
    int numSteps;

    Solver(const double dt, const int numSteps);

   public:
    virtual ~Solver();
    std::vector<Point> Solve(const Point startingPoint) const;
};