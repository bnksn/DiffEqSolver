#include "../../../src/solvers/solvers1D/solverTrig.hpp"
#include "gtest/gtest.h"

TEST(SolverTrigTests, CheckResults) {
    const auto expectedResults = std::vector<double>{0.0,
                                                     0.5,
                                                     0.93879128094518638,
                                                     1.2089424338792563,
                                                     1.2443110347131077,
                                                     1.0362376164395364,
                                                     0.63566580866606959,
                                                     0.14066956036584688,
                                                     -0.32755878327955129,
                                                     -0.65438059371135726,
                                                     -0.75977849342674708};

    const auto xFinal = 5.0;
    const auto xNumSteps = 10;
    const auto yInitial = 0.0;
    const auto coeffs = std::vector{1.0, 1.0};
    const auto trigFunc = TrigFunc::Cosine;

    const auto trigSolver =
        SolverTrig(xFinal, xNumSteps, yInitial, coeffs, trigFunc);
    const auto results = trigSolver.solve();

    ASSERT_EQ(expectedResults.size(), results.size());
    for (auto i = 0; i < results.size(); ++i) {
        ASSERT_NEAR(expectedResults[i], results[i], 1e-5) << "i = " << i;
    }
}