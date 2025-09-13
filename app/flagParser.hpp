#pragma once
#include <vector>
#include <string>
#include <map>
#include <optional>

namespace app
{
    enum class Flag
    {
    };

    struct InputArguments
    {
        std::vector<std::string> fileNames;
        std::map<Flag, double> flagArgumentVector;
    };

    std::optional<InputArguments> parseFlags(int argc, char const *argv[]);

}