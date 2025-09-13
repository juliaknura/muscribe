#include "flagParser.hpp"

#include <iostream>

namespace app
{
    std::optional<std::pair<Flag, double>> extractFlagWithArgument(int &currArgInx, char const *argv[])
    {
        const std::string flagStr{argv[currArgInx]};
        if (flagStr.size() < 2)
        {
            std::cerr << "Malformed flag argument\n";
            return std::nullopt;
        }

        switch (flagStr.at(1))
        {
            // identify flag
            // currArgInx++;
            // extract argument
        default:
            std::cerr << "Unknown flag " << flagStr.at(1) << "\n";
            return std::nullopt;
        }
    }

    std::optional<InputArguments> parseFlags(int argc, char const *argv[])
    {
        const auto argStart{1};
        auto currArgInx{argStart};
        std::vector<std::string> fileNames;
        std::map<Flag, double> flagArgumentVector;

        while (currArgInx < argc)
        {
            if (argv[currArgInx][0] == '-')
            {
                const auto extractedOpt{extractFlagWithArgument(currArgInx, argv)};
                if (extractedOpt)
                {
                    flagArgumentVector.emplace(extractedOpt.value());
                }
                else
                {
                    return std::nullopt;
                }
            }
            else
            {
                fileNames.push_back(argv[currArgInx]);
            }
            currArgInx++;
        }

        if (fileNames.empty())
        {
            std::cerr << "No filenames provided\n";
            return std::nullopt;
        }

        return {{.fileNames = std::move(fileNames),
                 .flagArgumentVector = std::move(flagArgumentVector)}};
    }

}