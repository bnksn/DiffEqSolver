#include "../../src/output/resultWriter.hpp"
#include "gtest/gtest.h"

class ResultWriterTests : public ::testing::Test {
   protected:
    std::filesystem::path testsOutput;
    std::filesystem::path testsResource;

    void SetUp() override {
        const auto currDir = std::filesystem::current_path();
        this->testsOutput = currDir / "../tests/output/testOutput";
        this->testsResource = currDir / "../tests/output/resource";
        std::filesystem::create_directory(this->testsOutput);
    }

    [[nodiscard]]
    std::string readFile(const std::filesystem::path& path) const {
        auto file = std::ifstream(path);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + path.string());
        }

        return {std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>()};
    }
};

TEST_F(ResultWriterTests, Write2d) {
    const auto xNumSteps = 5;
    const auto xFinal = 1;
    const auto fakeResults = std::vector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    const auto outputPath = this->testsOutput / "data2d.txt";

    const auto resultWriter = ResultWriter<double>(fakeResults, outputPath);
    resultWriter.write2d(xNumSteps, xFinal);

    const auto data = this->readFile(outputPath);
    const auto expectedData =
        readFile(this->testsResource / "data2dExpected.txt");

    ASSERT_EQ(expectedData, data);
}

TEST_F(ResultWriterTests, Write3d) {
    const auto xNumSteps = 5;
    const auto xFinal = 1;
    const auto yNumSteps = 2;
    const auto yFinal = 1;
    const auto fakeResults =
        std::vector{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 1.0, 2.0, 3.0,
                    4.0, 5.0, 6.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    const auto outputPath = this->testsOutput / "data3d.txt";

    const auto resultWriter = ResultWriter<double>(fakeResults, outputPath);
    resultWriter.write3d(xNumSteps, xFinal, yNumSteps, yFinal);

    const auto data = this->readFile(outputPath);
    const auto expectedData =
        readFile(this->testsResource / "data3dExpected.txt");

    ASSERT_EQ(expectedData, data);
}
