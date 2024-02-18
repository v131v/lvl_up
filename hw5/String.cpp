#include "String.h"

#include <cstring>

String::String():
    _cap(0),
    _len(0),
    _str(nullptr),
    _hash(0)
{}

String::String(const char c):
    _cap(2),
    _len(1),
    _str(new char[]{c, '\0'}),
    _hash(c)
{}

String::String(const char* s):
    _cap(strlen(s) + 1),
    _len(_cap - 1),
    _str(new char[_cap])
{
    strcpy(_str, s);
}

String::String(const String& b):
    _cap(b._cap),
    _len(b._len)
{
    if (_cap > 0) {
        _str = new char[_cap];
        strcpy(_str, b._str);
    }
}

String::String(String&& b):
    _cap(b._cap),
    _len(b._len),
    _str(b._str)
{
    b._cap = 0;
    b._len = 0;
    b._str = nullptr;
}

String::~String() {
    if (_str != nullptr) {
        delete[] _str;
    }
}

bool String::operator==(const String& b) const {
    return strcmp(_str, b._str) == 0;
}

bool String::operator!=(const String& b) const {
    return strcmp(_str, b._str) != 0;
}

String String::operator +(const String& b) const {
    String newStr(*this);
    newStr += b;
    return newStr;
}

String& String::operator +=(const String& b) {
    if (b.length() == 0) {
        return *this;
    }

    if (_len + b.length() + 1 > _cap || _str == nullptr) {
        _cap *= 2;
        if (_cap < _len + b.length() + 1) {
            _cap = _len + b.length() + 1;
        }

        char* result = new char[_cap];

        if (_str != nullptr) {
            strcpy(result, _str);
            delete[] _str;
        }

        _str = result;
    }

    strcpy(_str + _len, b._str);
    _len += b.length();

    return *this;
}

String& String::operator =(const String& b) {
    _cap = b._cap;
    _len = b._len;

    if (_cap > 0) {
        _str = new char[_cap];
        strcpy(_str, b._str);
    }

    return *this;
}

String& String::operator =(String&& b) {
    _cap = b._cap;
    _len = b._len;

    if (_str != nullptr) {
        delete[] _str;
    }
    _str = b._str;

    b._str = nullptr;
    return *this;
}

char& String::operator [](int i) {
    return _str[i];
}

const char& String::operator [](int i) const {
    return _str[i];
}

unsigned long String::length() const {
    return _len;
}

unsigned long String::capacity() const {
    return _cap;
}

void String::shrinkToFit() {
    if (_cap == _len + 1 || _str == nullptr) {
        return;
    }

    _cap = _len + 1;
    if (_len == 0) {
        _cap = 0;
    }

    char* result = nullptr;
    if (_cap > 0) {
        result = new char[_cap];

        if (_str != nullptr) {
            strcpy(result, _str);
            delete[] _str;
        }
    }

    _str = result;
}

const char* String::c_str() const {
    if (_str == nullptr) {
        return "";
    }
    return _str;
}
