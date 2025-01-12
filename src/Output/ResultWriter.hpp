#pragma once

#include <string>
#include <vector>

class ResultWriter final {
   private:
    std::vector<double> results;
    std::string resultsPath;

   public:
    ResultWriter(const std::vector<double>& results,
                 const std::string& resultPath) noexcept;

    void write2d(const int xNumSteps, const double xFinal) const;

    void write3d(const int xNumSteps, const double xFinal, const int yNumSteps,
                 const double yFinal) const;
};