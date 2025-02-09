#include "../../src/input/configReader.hpp"
#include "gtest/gtest.h"

class ConfigReaderTests : public ::testing::Test {
   protected:
    std::filesystem::path configPath;

    void SetUp() override {
        const auto currDir = std::filesystem::current_path();
        this->configPath = currDir / "../tests/input/resource/config.txt";
    }
};

TEST_F(ConfigReaderTests, ReadConfig) {
    const auto cfg = ConfigReader<double>().parseConfig(this->configPath);

    const auto resultPathExpected = "data.txt";
    const auto dimensionExpected = Dimension::Two;
    const auto solverExpected = SolverChoice::Trig;
    const auto trigFuncExpected = TrigFunc::Cosine;
    const auto boundaryConditionExpected = BoundaryCondition::Dirichlet;
    const auto waveConstantExpected = 0.11;
    const auto advectionConstantExpected = 0.12;
    const auto heatConstantExpected = 0.13;
    const auto xFinalExpected = 1.0;
    const auto xNumStepsExpected = 20;
    const auto yInitialExpected = 2.0;
    const auto zInitialExpected = std::vector{1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.5, 1.6, 1.6, 1.6, 1.6,
                                              1.6, 1.6, 1.6, 1.5, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0};
    const auto yFinalExpected = 2.0;
    const auto yNumStepsExpected = 200;
    const auto polynomialCoeffsExpected = std::vector{1.0, 1.0, 2.0};
    const auto trigCoeffsExpected = std::vector{1.0, 1.0};

    EXPECT_EQ(cfg.resultPath, resultPathExpected);
    EXPECT_EQ(cfg.dimension, dimensionExpected);
    EXPECT_EQ(cfg.solver, solverExpected);
    EXPECT_EQ(cfg.trigFunc, trigFuncExpected);
    EXPECT_EQ(cfg.boundaryCondition, boundaryConditionExpected);
    EXPECT_EQ(cfg.waveConstant, waveConstantExpected);
    EXPECT_EQ(cfg.advectionConstant, advectionConstantExpected);
    EXPECT_EQ(cfg.heatConstant, heatConstantExpected);
    EXPECT_EQ(cfg.xFinal, xFinalExpected);
    EXPECT_EQ(cfg.xNumSteps, xNumStepsExpected);
    EXPECT_EQ(cfg.yInitial, yFinalExpected);
    EXPECT_EQ(cfg.zInitial, zInitialExpected);
    EXPECT_EQ(cfg.yFinal, yFinalExpected);
    EXPECT_EQ(cfg.yNumSteps, yNumStepsExpected);
    EXPECT_EQ(cfg.polynomialCoeffs, polynomialCoeffsExpected);
    EXPECT_EQ(cfg.trigCoeffs, trigCoeffsExpected);
}