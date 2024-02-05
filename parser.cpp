#include "parser.h"
#include <iostream>
#include <stdexcept>

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
            parseExitStatement(i);
        } else {
            handleUnknownToken(token);
        }
    }
}

void parser::parseVariableAssignment(size_t& index) {
    if (index + 2 >= tokens.size()) {
        handleParsingError("Incomplete variable assignment");
        return;
    }

    std::string varName = tokens[++index];

    try {
        int value = std::stoi(tokens[++index]);
        variables[varName] = value;
    } catch (const std::invalid_argument& e) {
        handleParsingError("Invalid value in variable assignment");
    } catch (const std::out_of_range& e) {
        handleParsingError("Value out of range in variable assignment");
    }
}

void parser::parsePrintStatement(size_t& index) {
    if (index + 1 >= tokens.size()) {
        handleParsingError("Incomplete print statement");
        return;
    }

    std::string varName = tokens[++index];
    
    if (variables.find(varName) != variables.end()) {
        std::cout << varName << ": " << variables[varName] << std::endl;
    } else {
        handleParsingError("Variable not found in print statement");
    }
}