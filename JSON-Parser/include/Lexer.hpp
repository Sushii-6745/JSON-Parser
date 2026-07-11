#pragma once
#include <vector>
#include <string>
#include "Token.hpp"
class Lexer{
private:
    std::string filedata;
    std::vector<Token> tokens;
    void addToken(TokenType, const std::string &value="");
public:
    bool readFile(const std::string &path);
    bool tokenize();
    const std::vector<Token>& getTokens() const;
};