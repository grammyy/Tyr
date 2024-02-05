#include "parser.h"
#include <iostream>

parser::parser(const std::vector<std::string>& tokens, std::map<std::string, int>& variables)
    : tokens(tokens), variables(variables), addParser(tokens, variables), subtractParser(tokens, variables),
      multiplyParser(tokens, variables), divideParser(tokens, variables) {}

void parser::parse() {
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::string token = tokens[i];

        if (token == "let") {
            parseVariableAssignment(i);
        } else if (token == "print") {
            parsePrintStatement(i);
        } else if (token == "add") {
            addParser.parse(i);
        } else if (token == "multiply") {
            multiplyParser.parse(i);
        } else if (token == "divide") {
            divideParser.parse(i);
        } else if (token == "exit") {
            std::exit(0);
        }
    }
}

void parser::parseVariableAssignment(size_t& index) {
    std::string varName = tokens[++index];
    
    int value = std::stoi(tokens[++index]);
    
    variables[varName] = value;
}

void parser::parsePrintStatement(size_t& index) {
    std::string varName = tokens[++index];
    std::cout << varName << ": " << variables[varName] << std::endl;
}