#include "add.h"
#include <string>  // add this line

add::add(const std::vector<std::string>& tokens, std::map<std::string, int>& variables)
    : tokens(tokens), variables(variables) {}

void add::parse(size_t& index) {
    std::string varName = tokens[++index];
    
    int value = std::stoi(tokens[++index]);
    
    variables[varName] += value;
}