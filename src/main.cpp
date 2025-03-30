#include <iostream>
#include <memory>
#include <span>

#include "input/configReader.hpp"
#include "output/resultWriter.hpp"
#include "solvers/solvers1D/solverPolynomial.hpp"
#include "solvers/solvers1D/solverTrig.hpp"
#include "solvers/solvers2D/solverAdvection.hpp"
#include "solvers/solvers2D/solverHeat.hpp"
#include "solvers/solvers2D/solverWave.hpp"

template <Numeric NumT>
[[nodiscard]]
std::vector<double> getResults(const Config<NumT>& cfg) {
    switch (cfg.solver) {
        case (SolverChoice::Polynomial):
            return SolverPolynomial(cfg.xFinal, cfg.xNumSteps, cfg.yInitial, cfg.polynomialCoeffs)
                .solve();
        case (SolverChoice::Trig):
            return SolverTrig(cfg.xFinal, cfg.xNumSteps, cfg.yInitial, cfg.trigCoeffs, cfg.trigFunc)
                .solve();
        case (SolverChoice::Heat):
            return SolverHeat(cfg.xFinal, cfg.xNumSteps, cfg.yFinal, cfg.yNumSteps, cfg.zInitial,
                              cfg.heatConstant, cfg.boundaryCondition)
                .solve();
        case (SolverChoice::Advection):
            return SolverAdvection(cfg.xFinal, cfg.xNumSteps, cfg.yFinal, cfg.yNumSteps,
                                   cfg.zInitial, cfg.advectionConstant, cfg.boundaryCondition)
                .solve();
        case (SolverChoice::Wave):
            return SolverWave(cfg.xFinal, cfg.xNumSteps, cfg.yFinal, cfg.yNumSteps, cfg.zInitial,
                              cfg.waveConstant, cfg.boundaryCondition)
                .solve();
        default:
            throw std::invalid_argument("Invalid user input");
    }
}

int main(int argc, char* argv[]) {
    try {
        const auto args = std::span(argv, argc);

        if (argc != 2) {
            std::cerr << "Usage: " << args[0] << " <configRelativeToBinary>\n";
            return 1;
        }

        const auto configRelativeToBinary = args[1];
        const auto binaryDir = std::filesystem::canonical(args[0]).parent_path();
        const auto configPath = binaryDir / configRelativeToBinary;
        const auto cfg = ConfigReader<double>().parseConfig(configPath);

        const auto results = getResults(cfg);

        const auto outputPath = binaryDir / cfg.resultPath;
        const auto resultWriter = ResultWriter(results, outputPath);
        switch (cfg.dimension) {
            case (Dimension::Two):
                resultWriter.write2d(cfg.xNumSteps, cfg.xFinal);
                break;
            case (Dimension::Three):
                resultWriter.write3d(cfg.xNumSteps, cfg.xFinal, cfg.yNumSteps, cfg.yFinal);
                break;
            default:
                throw std::invalid_argument("Invalid dimension");
        }

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
}