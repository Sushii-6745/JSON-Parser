#include "Parser.hpp"
#include <stdexcept>
Parser::Parser(const std::vector<Token>& tokens){
    this->tokens = tokens;
    current = 0;
}
JSONType Parser::tokenToJSONType(std::string token){
    if(token == "LEFT_BRACE") return JSONType::OBJECT;
    else if(token == "LEFT_BRACKET") return JSONType::ARRAY;
    else if(token == "STRING") return JSONType::STRING;
    else if(token == "NUMBER") return JSONType::NUMBER;
    else if(token == "NULL_VALUE") return JSONType::NULL_VALUE;
    else if(token == "TRUE_VALUE") return JSONType::BOOLEAN;
    else return JSONType::BOOLEAN;
}
Node Parser::parseString(){
    Node node;
    node.type = JSONType::STRING;
    node.value = tokens[current].value;
    current++;
    return node;
}
Node Parser::parseNumber(){
    Node node;
    node.type = JSONType::NUMBER;
    node.value = tokens[current].value;
    current++;
    return node;
}
Node Parser::parseBoolean(){
    Node node;
    node.type = JSONType::BOOLEAN;
    if(tokens[current].type == TokenType::TRUE_VALUE)
        node.value = "true";
    else
        node.value = "false";
    current++;
    return node;
}
Node Parser::parseNull(){
    Node node;
    node.type = JSONType::NULL_VALUE;
    node.value = "null";
    current++;
    return node;
}
Node Parser::parseObject(){
    Node objectNode;
    objectNode.type = JSONType::OBJECT;
    current++;
    while(tokens[current].type != TokenType::RIGHT_BRACE)
    {
        if(tokens[current].type != TokenType::STRING)
            throw std::runtime_error("Expected key.");
        std::string key = tokens[current].value;
        current++;
        if(tokens[current].type != TokenType::COLON)
            throw std::runtime_error("Expected ':'.");
        current++;
        auto child = std::make_unique<Node>(parseValue());
        child->key = key;
        child->parent = &objectNode;
        objectNode.children.push_back(std::move(child));
        if(tokens[current].type == TokenType::COMMA)
        {
            current++;
        }
        else if(tokens[current].type != TokenType::RIGHT_BRACE)
        {
            throw std::runtime_error("Expected ',' or '}'.");
        }
    }
    current++;
    return objectNode;
}

Node Parser::parseArray(){   
    Node arrayNode;
    arrayNode.type = JSONType::ARRAY;
    current++;
    while(tokens[current].type != TokenType::RIGHT_BRACKET)
    {
        auto child = std::make_unique<Node>(parseValue());
        child->parent = &arrayNode;
        arrayNode.children.push_back(std::move(child));
        if(tokens[current].type == TokenType::COMMA)
        {
            current++;
        }
        else if(tokens[current].type != TokenType::RIGHT_BRACKET)
        {
            throw std::runtime_error("Expected ',' or ']'.");
        }
    }
    current++;
    return arrayNode;
}
Node Parser::parseValue(){
    switch(tokens[current].type)
    {
        case TokenType::STRING:
            return parseString();

        case TokenType::NUMBER:
            return parseNumber();

        case TokenType::TRUE_VALUE:
        case TokenType::FALSE_VALUE:
            return parseBoolean();

        case TokenType::NULL_VALUE:
                return parseNull();

        case TokenType::LEFT_BRACE:
            return parseObject();

        case TokenType::LEFT_BRACKET:
            return parseArray();

        default:
            throw std::runtime_error("Unexpected token");
    }
}

Node Parser::parse(){
    current = 0;
    Node root = parseValue();
    if(tokens[current].type != TokenType::END_OF_FILE)
        throw std::runtime_error("Unexpected tokens after JSON.");
    return root;
}
