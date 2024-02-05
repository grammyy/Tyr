#include "divide.h"

divide::divide(const std::vector<std::string>& tokens, std::map<std::string, int>& variables)
    : tokens(tokens), variables(variables) {}

void divide::parse(size_t& index) {
    std::string varName = tokens[++index];
    
    int value = std::stoi(tokens[++index]);
    
    variables[varName] /= value;
}