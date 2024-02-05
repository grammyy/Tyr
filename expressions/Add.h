#pragma once
#include <vector>
#include <map>
#include <string>

class add {
public:
    add(const std::vector<std::string>& tokens, std::map<std::string, int>& variables);
    
    void parse(size_t& index);

private:
    const std::vector<std::string>& tokens;
    std::map<std::string, int>& variables;
};