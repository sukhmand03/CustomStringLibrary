#include <iostream>
#include "MyString.h"

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3 = s1 + MyString(", ") + s2 + MyString("!");
    std::cout << "s3: " << s3.c_str() << " (length: " << s3.length() << ")\n";

    s3 += MyString(" How are you?");
    std::cout << "After append: " << s3.c_str() << "\n";

    MyString sub = s3.substring(7, 5);  // should be "World"
    std::cout << "Substring: " << sub.c_str() << "\n";

    std::cout << "Compare s1 vs s2: " << s1.compare(s2) << "\n";
    std::cout << "Compare s2 vs s2: " << s2.compare(s2) << "\n";

    MyString empty;
    std::cout << "Empty: '" << empty.c_str() << "' length=" << empty.length() << "\n";

    try {
        auto invalid = s1.substring(100, 5);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
