# CustomStringLibrary

A simple C++ library providing a custom `MyString` class with basic string operations and built-in logging.

## Features

- Dynamic string storage
- Concatenation (+, +=)
- Substring extraction with bounds checking
- Comparison (==, !=, compare)
- Copy/move constructors and assignment
- Logs actions to `myString.log`

## Build & Run

Using g++  
```bash
g++ -std=c++17 Logger.cpp MyString.cpp main.cpp -o demo
./demo
