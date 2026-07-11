# JSON Parser

A lightweight JSON parser written completely from scratch in Modern C++.

This project implements a complete JSON parsing pipeline including lexical analysis, recursive-descent parsing, and Abstract Syntax Tree (AST) generation without using any third-party JSON libraries.

---

## Features

- Character-level lexical analysis
- Tokenization of JSON input
- Recursive-descent parser
- AST (Abstract Syntax Tree) generation
- Supports:
  - Objects
  - Arrays
  - Strings
  - Numbers (integers)
  - Booleans (`true` / `false`)
  - `null`
- Recursive AST traversal and pretty printing
- Modular project structure (Lexer, Parser, AST)

---

## Project Structure

```
JSON-Parser/
│
├── include/
│   ├── JSON.hpp
│   ├── Lexer.hpp
│   ├── Parser.hpp
│   ├── Node.hpp
│   └── Token.hpp
│
├── src/
│   ├── JSON.cpp
│   ├── Lexer.cpp
│   ├── Parser.cpp
│   └── main.cpp
│
├── examples/
│   └── webapp.json
│
├── CMakeLists.txt
└── README.md
```

---

## How It Works

```
JSON File
      │
      ▼
 Lexer
      │
      ▼
  Tokens
      │
      ▼
 Recursive Descent Parser
      │
      ▼
 Abstract Syntax Tree (AST)
      │
      ▼
 Pretty Printed Output
```

---

## Build

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

Run:

```bash
./jsonparser
```

---

## Example

### Input

```json
{
    "name": "Ayush",
    "age": 19,
    "alive": true,
    "skills": [
        "C++",
        "Git"
    ]
}
```

### Output

```
OBJECT
    name : STRING = Ayush
    age : NUMBER = 19
    alive : BOOLEAN = true
    skills : ARRAY
        STRING = C++
        STRING = Git
```

---

## Technologies Used

- C++17
- STL
- CMake

---

## Future Improvements

- Floating-point number support
- Scientific notation (`1e9`)
- Escape sequence handling (`\"`, `\\`, `\n`)
- Unicode escape support
- Better error reporting (line and column numbers)
- JSON serialization (AST → JSON)
- Unit tests

---

## Learning Objectives

This project was built to gain a deeper understanding of:

- Compiler design fundamentals
- Lexical analysis
- Recursive-descent parsing
- Abstract Syntax Trees
- Modern C++ project organization
- CMake build system

---

## Implementation Highlights

- No external JSON parsing libraries used.
- Implemented a custom lexer and recursive-descent parser.
- Generates an AST using smart pointers (`std::unique_ptr`).
- Modular architecture separating lexical analysis, parsing, and AST representation.
