#include "JSON.hpp"
#include <iostream>
Node JSON::parseFile(const std::string& path){
    if(!lexer.readFile(path))
        throw std::runtime_error("Unable to read file.");
    lexer.tokenize();
    Parser parser(lexer.getTokens());
    return parser.parse();
}
void JSON::printTree(const Node& node, int depth){
    // indentation
    for(int i = 0; i < depth; i++)
        std::cout << "    ";
    // key
    if(!node.key.empty())
        std::cout << node.key << " : ";
    // type
    std::cout << JSONTypeToString(node.type);
    // primitive values
    if(node.type == JSONType::STRING || node.type == JSONType::NUMBER || node.type == JSONType::BOOLEAN || node.type == JSONType::NULL_VALUE){
        std::cout << " = " << node.value;
    }
    std::cout << '\n';
    // children
    for(const auto& child : node.children){
        printTree(*child, depth + 1);
    }
}