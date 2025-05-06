#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstddef>
#include <stdexcept>
#include "Logger.h"


class MyString {
public:
    MyString();                               /// Default: empty string
    MyString(const char* str);                /// From C‐string
    MyString(const MyString& other);          ///<Copy constructor
    MyString(MyString&& other) noexcept;      /// Move constructor
    ~MyString();                              /// Destructor

    MyString& operator=(const MyString&);     ///< Copy assignment
    MyString& operator=(MyString&&) noexcept; ///< Move assignment

    std::size_t length() const noexcept;      ///< Number of characters
    const char* c_str() const noexcept;       ///< c string pointer

    MyString operator+(const MyString& rhs) const; ///< Concatenation
    MyString& operator+=(const MyString& rhs);     ///< Append

    MyString substring(std::size_t pos, std::size_t len) const; ///< Extract substring

    int  compare(const MyString& other) const noexcept;  ///< strcmp‐style compare
    bool operator==(const MyString& other) const noexcept;
    bool operator!=(const MyString& other) const noexcept;

private:
    char*        data_;
    std::size_t  size_;
};

#endif // MYSTRING_H
