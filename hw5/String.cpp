#include "String.h"

#include <iostream>
#include <cstring>

String::String(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

String::String(String&& b) {
    str = b.str;
    b.str = nullptr;
}

String::~String() {
    delete[] str;
}

bool String::operator==(const String& b) const {
    return strcmp(str, b.str) == 0;
}

bool String::operator!=(const String& b) const {
    return strcmp(str, b.str) != 0;
}

String String::operator+(const String& b) const {
    char* result = new char[len + b.length() + 1];

    int i = 0, j = 0;
    while (str[i] != '\0') {
        result[j++] = str[i++];
    }

    i = 0;
    while (b.str[i] != '\0') {
        result[j++] = b.str[i++];
    }

    result[j] = '\0';

    return String(result);
}

String& String::operator+=(const String& b) {
    char* result = new char[len + b.length() + 1];

    int i = 0, j = 0;
    while (str[i] != '\0') {
        result[j++] = str[i++];
    }

    i = 0;
    while (b.str[i] != '\0') {
        result[j++] = b.str[i++];
    }

    result[j] = '\0';

    len += b.length();

    delete[] str;
    str = result;

    return *this;
}

char& String::operator[](int i) const {
    return str[i];
}

int String::length() const {
    return len;
}

void String::print() const {
    std::cout << str;
}
