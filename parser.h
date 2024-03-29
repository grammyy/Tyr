#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "expressions/add.h"
#include "expressions/subtract.h"
#include "expressions/multiply.h"
#include "expressions/divide.h"

class parser {
    public:
        parser(const std::vector<std::string>& tokens, std::map<std::string, int>& variables);
        
        void parse();

    private:
        void parseVariableAssignment(size_t& index);
        void parsePrintStatement(size_t& index);
        void parseExitStatement(size_t& index);
        void handleUnknownToken(const std::string& token);
        void handleParsingError(const std::string& errorMessage);
        
        add addParser;
        subtract subtractParser;
        multiply multiplyParser;
        divide divideParser;
        
        const std::vector<std::string>& tokens;
        std::map<std::string, int>& variables;
};