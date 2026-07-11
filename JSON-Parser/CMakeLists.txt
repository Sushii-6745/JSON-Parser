cmake_minimum_required(VERSION 3.10)

project(JSONParser VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/JSON.cpp
    src/Lexer.cpp
    src/Parser.cpp
    src/Node.cpp
    src/Token.cpp
)

# Executable
add_executable(jsonparser ${SOURCES})