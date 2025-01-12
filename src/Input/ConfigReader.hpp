#include <filesystem>
#include <fstream>
#include <unordered_map>

#include "UserInputs.hpp"

class ConfigReader final {
   private:
    [[nodiscard]]
    std::unordered_map<std::string, std::string> createConfigMap(
        const std::filesystem::path& configPath) const;

    template <typename T>
    [[nodiscard]]
    std::vector<T> stringToVec(const std::string& str) const
        requires std::integral<T> || std::floating_point<T>;

    [[nodiscard]]
    SolverChoice solverChoiceToEnum(const std::string_view solverChoice) const;

    [[nodiscard]]
    Dimension dimensionToEnum(const std::string_view dimension) const;

    [[nodiscard]]
    TrigFunc trigFuncToEnum(const std::string_view trigFunc) const;

    [[nodiscard]]
    BoundaryCondition boundaryConditionToEnum(
        const std::string_view boundaryCondition) const;

   public:
    [[nodiscard]]
    Config parseConfig(const std::filesystem::path& configPath) const;
};
