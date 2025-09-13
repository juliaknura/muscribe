#include <iostream>

#include "flagParser.hpp"

int main(int argc, char const *argv[])
{
    using namespace app;
    if (argc < 1)
    {
        std::cerr << "No arguments provided\n";
        return EXIT_FAILURE;
    }

    const auto inputArgumentsOpt{parseFlags(argc, argv)};
    if (not inputArgumentsOpt)
    {
        return EXIT_FAILURE;
    }
    const auto inputArguments{inputArgumentsOpt.value()};

    for (const auto &fileName : inputArguments.fileNames)
    {
        std::cout << fileName << "\n";
    }

    return EXIT_SUCCESS;
}
