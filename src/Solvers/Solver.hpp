#pragma once

#include <vector>

class Solver {
   protected:
    Solver() noexcept;

   public:
    [[nodiscard]] std::vector<double> virtual solve() const = 0;
};