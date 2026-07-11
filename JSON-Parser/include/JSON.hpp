#pragma once
#include "Lexer.hpp"
#include "Parser.hpp"
class JSON{
private:
    Lexer lexer;
public:
    Node parseFile(const std::string&);
    void printTree(const Node&,int depth=0);
};