#pragma once
#include <string>
enum class TokenType{
    LEFT_BRACE,
    RIGHT_BRACE,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    COLON,
    COMMA,
    STRING,
    NUMBER,
    TRUE_VALUE,
    FALSE_VALUE,
    NULL_VALUE,
    END_OF_FILE
};
struct Token{
    TokenType type;
    std::string value;
};
std::string tokenToString(Token token);