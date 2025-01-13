#pragma once

#include <vector>

class Solver {
   protected:
    Solver() noexcept;

   public:
    virtual ~Solver() noexcept;
    [[nodiscard]] std::vector<double> virtual solve() const = 0;
};