#include "MyString.h"
#include <cstring>
#include <algorithm>

/* Default constructor */
MyString::MyString()
  : data_(new char[1]()), size_(0)
{
    Logger::Instance().Log("Default constructed empty MyString");
}

/* From C‐string */
MyString::MyString(const char* str)
{
    if (!str) throw std::invalid_argument("Null C-string");
    size_ = std::strlen(str);
    data_ = new char[size_ + 1];
    std::memcpy(data_, str, size_ + 1);
    Logger::Instance().Log("Constructed from C-string: '" + std::string(data_) + "'");
}

/* Copy constructor */
MyString::MyString(const MyString& other)
  : data_(new char[other.size_ + 1]), size_(other.size_)
{
    std::memcpy(data_, other.data_, size_ + 1);
    Logger::Instance().Log("Copy constructed MyString: '" + std::string(data_) + "'");
}

/* Move constructor */
MyString::MyString(MyString&& other) noexcept
  : data_(other.data_), size_(other.size_)
{
    other.data_ = new char[1](); other.size_ = 0;
    Logger::Instance().Log("Move constructed MyString");
}

/* Destructor */
MyString::~MyString()
{
    Logger::Instance().Log("Destroyed MyString: '" + std::string(data_) + "'");
    delete[] data_;
}

/* Copy assignment */
MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::memcpy(data_, other.data_, size_ + 1);
        Logger::Instance().Log("Copy assigned MyString: '" + std::string(data_) + "'");
    }
    return *this;
}

/* Move assignment */
MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = new char[1](); other.size_ = 0;
        Logger::Instance().Log("Move assigned MyString");
    }
    return *this;
}

/* Length */
std::size_t MyString::length() const noexcept {
    return size_;
}

/* c_str */
const char* MyString::c_str() const noexcept {
    return data_;
}

/* Concatenation */
MyString MyString::operator+(const MyString& rhs) const {
    MyString result;
    delete[] result.data_;
    result.size_ = size_ + rhs.size_;
    result.data_ = new char[result.size_ + 1];
    std::memcpy(result.data_, data_, size_);
    std::memcpy(result.data_ + size_, rhs.data_, rhs.size_ + 1);
    Logger::Instance().Log("Concatenated MyString: '" + std::string(result.data_) + "'");
    return result;
}

/* Append */
MyString& MyString::operator+=(const MyString& rhs) {
    *this = *this + rhs;
    Logger::Instance().Log("Appended MyString, new value: '" + std::string(data_) + "'");
    return *this;
}

/* Substring */
MyString MyString::substring(std::size_t pos, std::size_t len) const {
    if (pos > size_) throw std::out_of_range("Substring position out of range");
    std::size_t rlen = std::min(len, size_ - pos);
    char* buffer = new char[rlen + 1];
    std::memcpy(buffer, data_ + pos, rlen);
    buffer[rlen] = '\0';
    MyString sub(buffer);
    delete[] buffer;
    Logger::Instance().Log("Extracted substring: '" + std::string(sub.c_str()) + "'");
    return sub;
}

/* Compare */
int MyString::compare(const MyString& other) const noexcept {
    return std::strcmp(data_, other.data_);
}

/* Equality */
bool MyString::operator==(const MyString& other) const noexcept {
    return compare(other) == 0;
}
bool MyString::operator!=(const MyString& other) const noexcept {
    return compare(other) != 0;
}
