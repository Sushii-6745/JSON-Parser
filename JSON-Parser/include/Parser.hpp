#pragma once
#include "Token.hpp"
#include "Node.hpp"
class Parser{
private:
    std::vector<Token> tokens;
    size_t current;
    Node parseValue();
    Node parseObject();
    Node parseArray();
    Node parseString();
    Node parseNumber();
    Node parseBoolean();
    Node parseNull();
    JSONType tokenToJSONType(std::string token);
public:
    Parser(const std::vector<Token> &tokens);
    Node parse();
};