#pragma once

#include <vector>

#include "../Math/Point.hpp"

class Solver {
   private:
    double virtual rhsFunction(const double t) const = 0;

   protected:
    double dt;
    int numSteps;
    std::vector<int> coeffs;

    Solver(const double dt, const int numSteps, const std::vector<int>& coeffs);

   public:
    virtual ~Solver();
    std::vector<Point> Solve(const Point startingPoint) const;
};