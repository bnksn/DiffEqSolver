#pragma once

#include <string>
#include <vector>

class ResultWriter final {
   public:
    void write2d(const std::vector<double>& results,
                 const std::string& resultPath, const int xNumSteps,
                 const double xFinal) const;

    void write3d(const std::vector<double>& results,
                 const std::string& resultPath, const int xNumSteps,
                 const double xFinal, const int yNumSteps,
                 const double yFinal) const;

    ResultWriter() noexcept;
};