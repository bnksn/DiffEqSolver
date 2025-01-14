#include "../../src/Output/ResultWriter.hpp"
#include "gtest/gtest.h"

std::string readFile(const std::string& path) {
    auto file = std::ifstream(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    return std::string(std::istreambuf_iterator<char>(file),
                       std::istreambuf_iterator<char>());
}

TEST(ResultWriterTests, Write2d) {
    const auto xNumSteps = 5;
    const auto xFinal = 1;
    const auto fakeResults = std::vector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    const auto outputPath = "tests/Output/TestOutput/data2d.txt";

    const auto resultWriter = ResultWriter<double>(fakeResults, outputPath);
    resultWriter.write2d(xNumSteps, xFinal);

    const auto data = readFile(outputPath);
    const auto expectedData =
        readFile("tests/Output/Resource/data2dExpected.txt");

    ASSERT_EQ(expectedData, data);
}

TEST(ResultWriterTests, Write3d) {
    const auto xNumSteps = 5;
    const auto xFinal = 1;
    const auto yNumSteps = 2;
    const auto yFinal = 1;
    const auto fakeResults =
        std::vector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    const auto outputPath = "tests/Output/TestOutput/data3d.txt";

    const auto resultWriter = ResultWriter<double>(fakeResults, outputPath);
    resultWriter.write3d(xNumSteps, xFinal, yNumSteps, yFinal);

    const auto data = readFile(outputPath);
    const auto expectedData =
        readFile("tests/Output/Resource/data3dExpected.txt");

    ASSERT_EQ(expectedData, data);
}
