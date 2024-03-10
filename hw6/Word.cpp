#include "Word.h"

#include <algorithm>
#include <cstring>

Word::Word():
    _cap(0),
    _len(0),
    _str(nullptr),
    _hash(0)
{}

Word::Word(const char c):
    _cap(2),
    _len(1),
    _str(new char[]{c, '\0'}),
    _hash(c-'a')
{}

Word::Word(const char* s) {
    const unsigned long len = strlen(s);
    if (len == 0) {
        _cap = 0;
        _len = 0;
        _str = nullptr;
        _hash = 0;
        return;
    }

    _cap = std::min(len + 1, minCap);
    _len = len;
    _str = new char[_cap];
    strcpy(_str, s);
    hash();
}

Word::Word(const Word& b):
    _cap(b.capacity()),
    _len(b.length()),
    _str(nullptr),
    _hash(b.hash())
{
    if (_cap > 0) {
        _str = new char[_cap];
        strcpy(_str, b._str);
    }
}

Word::Word(Word&& b):
    _cap(b.capacity()),
    _len(b.length()),
    _str(b._str),
    _hash(b.hash())
{
    b._cap = 0;
    b._len = 0;
    b._str = nullptr;
    b._hash = 0;
}

Word::~Word() {
    if (_str != nullptr) {
        delete[] _str;
    }
}

bool Word::operator ==(const Word& b) const {
    if (hash() != b.hash()) {
        return false;
    }
    if (_str == nullptr && b._str == nullptr) {
        return true;
    }
    if ((_str == nullptr) ^ (b._str == nullptr)) {
        return false;
    }
    return strcmp(_str, b.c_str()) == 0;
}

bool Word::operator !=(const Word& b) const {
    return !(*this == b);
}

Word&& Word::operator +(const Word& b) const {
    Word newStr(*this);
    newStr += b;
    return std::move(newStr);
}

Word& Word::operator +=(const Word& b) {
    if (b.length() == 0) {
        return *this;
    }

    if (_len + b.length() + 1 > _cap || _str == nullptr) {
        _cap = std::max(minCap, std::max(_cap * 2, _len + b.length() + 1));

        char* result = new char[_cap];

        if (_str != nullptr) {
            strcpy(result, _str);
            delete[] _str;
        }

        _str = result;
    }

    strcpy(_str + _len, b.c_str());
    _len += b.length();

    for (unsigned long i = 0; i < b.length(); ++i) {
        _hash = (_hash * hashBase) % hashMod;
    }
    _hash = (_hash + b.hash()) % hashMod;

    return *this;
}

Word& Word::operator =(const Word& b) {
    _cap = b.capacity();
    _len = b.length();
    _hash = b.hash();

    if (_cap > 0) {
        _str = new char[_cap];
        strcpy(_str, b.c_str());
    }

    return *this;
}

Word& Word::operator =(Word&& b) {
    _cap = b.capacity();
    _len = b.length();
    _hash = b.hash();

    if (_str != nullptr) {
        delete[] _str;
    }
    _str = b._str;

    b._str = nullptr;
    return *this;
}

char& Word::operator [](int i) {
    return _str[i];
}

const char& Word::operator [](int i) const {
    return _str[i];
}

unsigned long Word::length() const {
    return _len;
}

unsigned long Word::capacity() const {
    return _cap;
}

void Word::shrinkToFit() {
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

const char* Word::c_str() const {
    if (_str == nullptr) {
        return "";
    }
    return _str;
}

unsigned long long Word::hash() const {
    if (_hash == 0 && _str != nullptr) {
        for (unsigned long i = 0; i < _len; ++i) {
            _hash = (_hash * hashBase) % hashMod;
            _hash = (_hash + _str[i] - 'a') % hashMod;
        }
    }

    return _hash;
}
