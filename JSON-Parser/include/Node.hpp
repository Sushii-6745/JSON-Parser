#pragma once
#include <string>
#include <vector>
#include <memory>
enum class JSONType{
    OBJECT,
    ARRAY,
    STRING,
    NUMBER,
    BOOLEAN,
    NULL_VALUE
};
struct Node{
    std::string key;
    JSONType type;
    std::string value;
    Node* parent = nullptr;
    std::vector<std::unique_ptr<Node>> children;
};
std::string JSONTypeToString(JSONType type);