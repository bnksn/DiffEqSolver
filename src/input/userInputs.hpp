#pragma once

#include <string>
#include <vector>

#include "../concepts.hpp"

enum class BoundaryCondition { Dirichlet, Neumann };
enum class TrigFunc { Sine, Cosine, Tangent };
enum class SolverChoice { Polynomial, Trig, Heat, Advection, Wave };
enum class Dimension { Two, Three };

template <Numeric NumT>
struct Config {
    std::string resultPath{};
    Dimension dimension{};
    SolverChoice solver{};
    TrigFunc trigFunc{};
    BoundaryCondition boundaryCondition{};
    NumT xFinal{};
    int xNumSteps{};
    NumT yInitial{};
    std::vector<NumT> zInitial{};
    NumT yFinal{};
    int yNumSteps{};
    NumT waveConstant{};
    NumT advectionConstant{};
    NumT heatConstant{};
    std::vector<NumT> polynomialCoeffs{};
    std::vector<NumT> trigCoeffs{};
};