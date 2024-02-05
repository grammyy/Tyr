#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include "parser.h"

class interpreter {
    public:
        void runFromFile(const std::string& filename) {
            std::ifstream file(filename);

            if (file.is_open()) {
                std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                tokenize(code);

                parser parser(tokens, variables);
                parser.parse();
            } else {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
            }
        }

    private:
        std::vector<std::string> tokens;
        std::map<std::string, int> variables;

        void tokenize(const std::string& code) {
            std::istringstream iss(code);
            std::string token;

            while (iss >> token) {
                tokens.push_back(token);
            }
        }
};