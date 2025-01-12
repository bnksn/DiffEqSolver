
#include "ResultWriter.hpp"

#include <fstream>
#include <iostream>

ResultWriter::ResultWriter(const std::vector<double>& results,
                           const std::filesystem::path& resultsPath) noexcept {
    this->results = results;
    this->resultsPath = resultsPath;
}

void ResultWriter::write2d(const int xNumSteps, const double xFinal) const {
    const auto xStepSize = xFinal / xNumSteps;

    auto file = std::ofstream(this->resultsPath);

    auto zIndex = 0;
    for (auto xCurrStep = 0; xCurrStep < xNumSteps; ++xCurrStep) {
        const auto x = xStepSize * xCurrStep;
        const auto y = this->results[zIndex++];
        file << x << ',' << y << ' ';
    }

    file.close();
}

void ResultWriter::write3d(const int xNumSteps, const double xFinal,
                           const int yNumSteps, const double yFinal) const {
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