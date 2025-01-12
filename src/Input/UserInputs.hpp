#pragma once

#include <string>
#include <vector>

enum class BoundaryCondition { Dirichlet, Neumann };
enum class TrigFunc { Sine, Cosine, Tangent };
enum class SolverChoice { Polynomial, Trig, Heat, Advection, Wave };
enum class Dimension { Two, Three };

struct Config {
    std::string resultPath;
    Dimension dimension;
    SolverChoice solver;
    TrigFunc trigFunc;
    BoundaryCondition boundaryCondition;
    double xFinal;
    int xNumSteps;
    double yInitial;
    std::vector<double> zInitial;
    double yFinal;
    int yNumSteps;
    double waveConstant;
    double advectionConstant;
    double heatConstant;
    std::vector<double> polynomialCoeffs;
    std::vector<double> trigCoeffs;
};