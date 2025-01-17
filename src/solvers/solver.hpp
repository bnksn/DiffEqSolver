#pragma once

#include <vector>

class Solver {
   public:
    Solver() = default;
    virtual ~Solver() noexcept = default;
    Solver(const Solver&) = default;
    Solver& operator=(const Solver&) = default;
    Solver(Solver&&) = default;
    Solver& operator=(Solver&&) = default;

    [[nodiscard]] std::vector<double> virtual solve() const = 0;
};