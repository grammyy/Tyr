#pragma once
#include <vector>
#include <map>
#include <string>

class parser {
public:
    parser(const std::vector<std::string>& tokens, std::map<std::string, int>& variables);
    void parse();

private:
    void parseVariableAssignment(size_t& index);
    void parsePrintStatement(size_t& index);
    void parseAddition(size_t& index);

    const std::vector<std::string>& tokens;
    std::map<std::string, int>& variables;
};