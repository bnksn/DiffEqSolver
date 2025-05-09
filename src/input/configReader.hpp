#include <filesystem>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "../concepts.hpp"
#include "userInputs.hpp"

template <Numeric NumT>
class ConfigReader final {
   private:
    [[nodiscard]]
    std::unordered_map<std::string, std::string> createConfigMap(
        const std::filesystem::path& configPath) const {
        auto config = std::unordered_map<std::string, std::string>();

        auto file = std::ifstream(configPath);
        if (file.is_open()) {
            for (auto line = std::string(); std::getline(file, line);) {
                const auto pos = line.find('=');
                if (pos != std::string::npos) {
                    const auto key = line.substr(0, pos);
                    const auto value = line.substr(pos + 1);
                    config[key] = value;
                }
            }

            file.close();
        } else {
            std::cerr << "Failed to open config file: " << configPath << '\n';
        }

        return config;
    }

    [[nodiscard]]
    std::vector<NumT> stringToVec(const std::string& str) const {
        auto result = std::vector<NumT>();
        auto iss = std::istringstream(str);

        for (NumT val; iss >> val;) {
            result.push_back(val);
            if (iss.peek() == ',') {
                iss.ignore();
            }
        }

        return result;
    }

    [[nodiscard]]
    NumT stringToNum(const std::string& str) const {
        auto iss = std::istringstream(str);
        auto val = NumT();
        if (!(iss >> val)) {
            throw std::runtime_error("Failed cast from string to num type. Input: " + str);
        }

        return val;
    }

    [[nodiscard]]
    SolverChoice solverChoiceToEnum(const std::string_view solverChoice) const {
        if (solverChoice == "polynomial") {
            return SolverChoice::Polynomial;
        }
        if (solverChoice == "trig") {
            return SolverChoice::Trig;
        }
        if (solverChoice == "heat") {
            return SolverChoice::Heat;
        }
        if (solverChoice == "advection") {
            return SolverChoice::Advection;
        }
        if (solverChoice == "wave") {
            return SolverChoice::Wave;
        }
        throw std::invalid_argument("Invalid solver choice");
    }

    [[nodiscard]]
    Dimension dimensionToEnum(const std::string_view dimension) const {
        if (dimension == "2") {
            return Dimension::Two;
        }
        if (dimension == "3") {
            return Dimension::Three;
        }
        throw std::invalid_argument("Invalid dimension");
    }

    [[nodiscard]]
    TrigFunc trigFuncToEnum(const std::string_view trigFunc) const {
        if (trigFunc == "sine") {
            return TrigFunc::Sine;
        }
        if (trigFunc == "cosine") {
            return TrigFunc::Cosine;
        }
        if (trigFunc == "tangent") {
            return TrigFunc::Tangent;
        }
        throw std::invalid_argument("Invalid trig function");
    }

    [[nodiscard]]
    BoundaryCondition boundaryConditionToEnum(const std::string_view boundaryCondition) const {
        if (boundaryCondition == "dirichlet") {
            return BoundaryCondition::Dirichlet;
        }
        if (boundaryCondition == "neumann") {
            return BoundaryCondition::Neumann;
        }
        throw std::invalid_argument("Invalid boundary condition");
    }

   public:
    [[nodiscard]]
    Config<NumT> parseConfig(const std::filesystem::path& configPath) const {
        const auto config = createConfigMap(configPath);

        const auto& resultPath = config.at("resultPath");
        const auto dimension = dimensionToEnum(config.at("dimension"));
        const auto solverChoice = solverChoiceToEnum(config.at("solver"));
        const auto trigFunc = trigFuncToEnum(config.at("trigFunc"));
        const auto boundaryCondition = boundaryConditionToEnum(config.at("boundaryCondition"));
        const auto xFinal = stringToNum(config.at("xFinal"));
        const auto xNumSteps = std::stoi(config.at("xNumSteps"));
        const auto yInitial = stringToNum(config.at("yInitial"));
        const auto zInitial = stringToVec(config.at("zInitial"));
        const auto yFinal = stringToNum(config.at("yFinal"));
        const auto yNumSteps = std::stoi(config.at("yNumSteps"));
        const auto waveConstant = stringToNum(config.at("waveConstant"));
        const auto advectionConstant = stringToNum(config.at("advectionConstant"));
        const auto heatConstant = stringToNum(config.at("heatConstant"));
        const auto polynomialCoeffs = stringToVec(config.at("polynomialCoeffs"));
        const auto trigCoeffs = stringToVec(config.at("trigCoeffs"));

        return {resultPath,        dimension,    solverChoice,     trigFunc,
                boundaryCondition, xFinal,       xNumSteps,        yInitial,
                zInitial,          yFinal,       yNumSteps,        waveConstant,
                advectionConstant, heatConstant, polynomialCoeffs, trigCoeffs};
    };
};
