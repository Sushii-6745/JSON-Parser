#include "Lexer.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <iostream>
void Lexer::addToken(TokenType type, const std::string &value){
    tokens.push_back({type, value});
}
bool Lexer::readFile(const std::string &path){
    filedata.clear();
    std::ifstream file(path);
    if(!file.is_open())
        return false;
    std::stringstream buffer;
    buffer << file.rdbuf();
    filedata = buffer.str();
    file.close();
    return true;
}
bool Lexer::tokenize(){
    tokens.clear();
    for(size_t i = 0; i < filedata.size(); i++){
        char character = filedata[i];
        if(std::isspace(static_cast<unsigned char>(character)))
            continue;
        switch(character){
            case '{':
                addToken(TokenType::LEFT_BRACE);
                break;
            case '}':
                addToken(TokenType::RIGHT_BRACE);
                break;
            case '[':
                addToken(TokenType::LEFT_BRACKET);
                break;
            case ']':
                addToken(TokenType::RIGHT_BRACKET);
                break;
            case ':':
                addToken(TokenType::COLON);
                break;
            case ',':
                addToken(TokenType::COMMA);
                break;
            case '"':{
                std::string word;
                i++;
                while(i < filedata.size() && filedata[i] != '"'){
                    word += filedata[i];
                    i++;
                }
                addToken(TokenType::STRING, word);
                break;
            }
            default:
                if((character >= '0' && character <= '9') || character == '-'){
                    std::string number;
                    if(character == '-'){
                        number += '-';
                        i++;
                    }
                    while(i < filedata.size() && filedata[i] >= '0' && filedata[i] <= '9'){
                        number += filedata[i];
                        i++;
                    }

                    i--;

                    addToken(TokenType::NUMBER, number);
                }

                else if(i + 3 < filedata.size() && filedata.substr(i,4) == "true"){
                    addToken(TokenType::TRUE_VALUE);
                    i += 3;
                }

                else if(i + 4 < filedata.size() && filedata.substr(i,5) == "false"){
                    addToken(TokenType::FALSE_VALUE);
                    i += 4;
                }

                else if(i + 3 < filedata.size() &&  filedata.substr(i,4) == "null"){
                    addToken(TokenType::NULL_VALUE);
                    i += 3;
                }

                else{
                    std::cerr << "Unknown character: "
                              << character << '\n';
                    return false;
                }
        }
    }
    addToken(TokenType::END_OF_FILE);
    return true;
}
const std::vector<Token>& Lexer::getTokens() const{
    return tokens;
}