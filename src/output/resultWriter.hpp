#pragma once

#include <filesystem>
#include <fstream>
#include <vector>

#include "../concepts.hpp"

template <Numeric CoordT>
class ResultWriter final {
   private:
    std::vector<CoordT> results;
    std::filesystem::path resultsPath;

   public:
    ResultWriter(const std::vector<CoordT>& results,
                 const std::filesystem::path& resultsPath) noexcept
        : results(results), resultsPath(std::move(resultsPath)) {}

    void write2d(const int xNumSteps, const CoordT xFinal) const {
        const auto xStepSize = xFinal / xNumSteps;

        auto file = std::ofstream(this->resultsPath);

        auto yIndex = 0;
        for (auto xCurrStep = 0; xCurrStep < xNumSteps; ++xCurrStep) {
            const auto x = xStepSize * xCurrStep;
            const auto y = this->results[yIndex++];
            file << x << ',' << y << ' ';
        }

        file.close();
    }

    void write3d(const int xNumSteps, const CoordT xFinal, const int yNumSteps,
                 const CoordT yFinal) const {
        const auto xStepSize = xFinal / xNumSteps;
        const auto yStepSize = yFinal / yNumSteps;

        auto file = std::ofstream(this->resultsPath);

        auto zIndex = 0;
        for (auto yCurrStep = 0; yCurrStep <= yNumSteps; ++yCurrStep) {
            for (auto xCurrStep = 0; xCurrStep <= xNumSteps; ++xCurrStep) {
                const auto x = xStepSize * xCurrStep;
                const auto y = yStepSize * yCurrStep;
                const auto z = this->results[zIndex++];
                file << x << ',' << y << ',' << z << ' ';
            }
        }

        file.close();
    }
};