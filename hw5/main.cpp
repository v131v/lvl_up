#include "String.h"

#include <iostream>

int main() {
    String s1("hello");
    String s2("world");

    String s3(std::move(s1));
    std::cout << std::endl;

    String hw = s3 + s2;
    for (int i = 0; i < hw.length(); i++) {
        std::cout << hw[i];
    }
    std::cout << std::endl;

    return 0;
}
