#include "../../../src/solvers/solvers2D/solverHeat.hpp"
#include "gtest/gtest.h"

TEST(SolverTests, CheckResults) {
    const auto expectedResults = std::vector<double>{
        1,       2,       2,       3,       2,       2,       1,       1,       1.78667, 2.21333,
        2.57333, 2.21333, 1.78667, 1,       1,       1.70987, 2.19911, 2.41973, 2.19911, 1.70987,
        1,       1,       1.6628,  2.14181, 2.3256,  2.14181, 1.6628,  1,       1,       1.62359,
        2.07883, 2.24718, 2.07883, 1.62359, 1,       1,       1.58768, 2.01763, 2.17535, 2.01763,
        1.58768, 1,       1,       1.55403, 1.95955, 2.10805, 1.95955, 1.55403, 1};

    const auto xFinal = 5.0;
    const auto xNumSteps = 4;
    const auto yFinal = 1.0;
    const auto yNumSteps = 6;
    const auto zInitial = std::vector{1.0, 2.0, 2.0, 3.0, 2.0, 2.0, 1.0};
    const auto heatConstant = 2.0;
    const auto boundaryCondition = BoundaryCondition::Dirichlet;

    const auto heatSolver =
        SolverHeat(xFinal, xNumSteps, yFinal, yNumSteps, zInitial, heatConstant, boundaryCondition);
    const auto results = heatSolver.solve();

    ASSERT_EQ(expectedResults.size(), results.size());
    for (auto i = 0; i < results.size(); ++i) {
        ASSERT_NEAR(expectedResults[i], results[i], 1e-5) << "i = " << i;
    }
}
