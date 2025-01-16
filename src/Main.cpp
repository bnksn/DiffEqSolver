#include <iostream>
#include <memory>

#include "Input/ConfigReader.hpp"
#include "Output/ResultWriter.hpp"
#include "Solvers/Solvers1D/SolverPolynomial.hpp"
#include "Solvers/Solvers1D/SolverTrig.hpp"
#include "Solvers/Solvers2D/SolverAdvection.hpp"
#include "Solvers/Solvers2D/SolverHeat.hpp"
#include "Solvers/Solvers2D/SolverWave.hpp"

template <typename NumT>
    requires std::floating_point<NumT>
[[nodiscard]]
std::vector<double> getResults(const Config<NumT>& cfg) {
    switch (cfg.solver) {
        case (SolverChoice::Polynomial):
            return SolverPolynomial(cfg.xFinal, cfg.xNumSteps, cfg.yInitial,
                                    cfg.polynomialCoeffs)
                .solve();
        case (SolverChoice::Trig):
            return SolverTrig(cfg.xFinal, cfg.xNumSteps, cfg.yInitial,
                              cfg.trigCoeffs, cfg.trigFunc)
                .solve();
        case (SolverChoice::Heat):
            return SolverHeat(cfg.xFinal, cfg.xNumSteps, cfg.yFinal,
                              cfg.yNumSteps, cfg.zInitial, cfg.heatConstant,
                              cfg.boundaryCondition)
                .solve();
        case (SolverChoice::Advection):
            return SolverAdvection(cfg.xFinal, cfg.xNumSteps, cfg.yFinal,
                                   cfg.yNumSteps, cfg.zInitial,
                                   cfg.advectionConstant, cfg.boundaryCondition)
                .solve();
        case (SolverChoice::Wave):
            return SolverWave(cfg.xFinal, cfg.xNumSteps, cfg.yFinal,
                              cfg.yNumSteps, cfg.zInitial, cfg.waveConstant,
                              cfg.boundaryCondition)
                .solve();
        default:
            throw std::invalid_argument("Invalid user input");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <configRelativeToBinary>\n";
        return 1;
    }

    const auto configRelativeToBinary = argv[1];
    const auto binaryDir = std::filesystem::canonical(argv[0]).parent_path();
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
            resultWriter.write3d(cfg.xNumSteps, cfg.xFinal, cfg.yNumSteps,
                                 cfg.yFinal);
            break;
        default:
            throw std::invalid_argument("Invalid dimension");
    }
}