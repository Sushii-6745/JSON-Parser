#include "Node.hpp"
std::string JSONTypeToString(JSONType type){
    switch(type){
        case JSONType::OBJECT: return "OBJECT";
        case JSONType::ARRAY: return "ARRAY";
        case JSONType::STRING: return "STRING";
        case JSONType::NUMBER: return "NUMBER";
        case JSONType::BOOLEAN: return "BOOLEAN";
        case JSONType::NULL_VALUE: return "NULL";
    }
   return "";
}