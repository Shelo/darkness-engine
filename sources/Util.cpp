#include "Util.h"

std::string readFile(const std::string path)
{
    std::ifstream input(path);

    if (!input) {
        ERROR("File not found.")
    }

    std::stringstream stream;
    stream << input.rdbuf();
    return stream.str();
}
