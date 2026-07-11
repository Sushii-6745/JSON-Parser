#include <iostream>
#include "JSON.hpp"
int main(){   
    try{
        JSON json;
        Node root = json.parseFile("examples/webapp.json");
        json.printTree(root);
    }
    catch(const std::exception &e){
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}