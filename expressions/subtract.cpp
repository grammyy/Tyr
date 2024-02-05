#include "subtract.h"
#include <string>

subtract::subtract(const std::vector<std::string>& tokens, std::map<std::string, int>& variables)
    : tokens(tokens), variables(variables) {}

void subtract::parse(size_t& index) {
    std::string varName = tokens[++index];

    int value = std::stoi(tokens[++index]);

    variables[varName] -= value;
}