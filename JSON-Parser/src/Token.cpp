#include "Token.hpp"
std::string tokenToString(Token token){
    if(token.type == TokenType::COLON) return "COLON";
    else if(token.type == TokenType::COMMA) return "COMMA";
    else if(token.type == TokenType::LEFT_BRACE) return "LEFT_BRACE";
    else if(token.type == TokenType::RIGHT_BRACE) return "RIGHT_BRACE";
    else if(token.type == TokenType::LEFT_BRACKET) return "LEFT_BRACKET";
    else if(token.type == TokenType::RIGHT_BRACKET) return "RIGHT_BRACKET";
    else if(token.type == TokenType::TRUE_VALUE) return "TRUE_VALUE";
    else if(token.type == TokenType::FALSE_VALUE) return "FALSE_VALUE";
    else if(token.type == TokenType::NULL_VALUE) return "NULL_VALUE";
    else if(token.type == TokenType::STRING) return "STRING";
    else if(token.type == TokenType::NUMBER) return "NUMBER";
    else if(token.type == TokenType::END_OF_FILE) return "END_OF_FILE";
    else return "";
}