#include "Word.h"

#include <algorithm>
#include <cstring>

Word::Word()
    : _capacity(minCap)
    , _length(0)
    , _data(new char[_capacity + 1]{})
    , _hash(0)
{}

Word::Word(const char* s)
    : _capacity(std::min(strlen(s), minCap))
    , _length(strlen(s))
    , _data(new char[_capacity + 1]{})
    , _hash(0)
{
    if (_length > 0) {
        strncpy(_data, s, _length);
        _hash = hash();
    }
}

Word::Word(const Word& other)
    : _capacity(other._capacity)
    , _length(other._length)
    , _data(new char[_capacity + 1]{})
    , _hash(other._hash)
{
    if (_length > 0) {
        strncpy(_data, other._data, _length);
    }
}

Word::Word(Word&& other)
    : _capacity(other._capacity)
    , _length(other._length)
    , _data(other._data)
    , _hash(other._hash)
{
    other._capacity = 0;
    other._length = 0;
    other._data = nullptr;
    other._hash = 0;
}

Word::~Word() {
    delete[] _data;
}

void Word::swap(Word& other) noexcept {
    using std::swap;
    swap(_capacity, other._capacity);
    swap(_length, other._length);
    swap(_data, other._data);
    swap(_hash, other._hash);
}

bool operator == (const Word& a, const Word& b) {
    if (a.hash() != b.hash() || a.length() != b.length()) {
        return false;
    }
    return strncmp(a._data, b._data, a.length()) == 0;
}

bool operator != (const Word& a, const Word& b) {
    return !(a == b);
}

Word operator + (const Word& a, const Word& b) {
    Word newStr(a);
    newStr += b;
    return newStr;
}

Word& Word::operator += (const Word& other) {
    if (other.length() == 0) {
        return *this;
    }

    if (_length + other._length > _capacity) {
        _capacity = std::max(minCap, std::max(_capacity * 2, _length + other._length));

        char* result = new char[_capacity + 1];

        strncpy(result, _data, _length);
        delete[] _data;

        _data = result;
    }

    strncpy(_data + _length, other._data, other._length);
    _length += other._length;

    for (unsigned long i = 0; i < other._length; ++i) {
        _hash = (_hash * hashBase) % hashMod;
    }
    _hash = (_hash + other._hash) % hashMod;

    return *this;
}

Word& Word::operator += (char c) {
    if (_length + 1 > _capacity) {
        _capacity = std::max(minCap, std::max(_capacity * 2, _length + 1));

        char* result = new char[_capacity + 1];

        strncpy(result, _data, _length);
        delete[] _data;

        _data = result;
    }

    _data[_length] = c;
    ++_length;

    _hash = (_hash * hashBase) % hashMod;
    _hash = (_hash + (c-'a')) % hashMod;

    return *this;
}

Word& Word::operator = (const Word& other) {
    Word copied(other);
    swap(copied);
    return *this;
}

Word& Word::operator = (Word&& other) {
    Word moved(std::move(other));
    swap(moved);
    return *this;
}

char& Word::operator [] (int i) {
    return _data[i];
}

const char& Word::operator [] (int i) const {
    return _data[i];
}

unsigned long Word::length() const {
    return _length;
}

unsigned long Word::capacity() const {
    return _capacity;
}

const char* Word::c_str() const {
    if (_data == nullptr) {
        return "";
    }
    return _data;
}

unsigned long long Word::hash() const {
    unsigned long hash = _hash;

    if (hash == 0) {
        for (unsigned long i = 0; i < _length; ++i) {
            hash = (hash * hashBase) % hashMod;
            hash = (hash + _data[i] - 'a') % hashMod;
        }
    }

    return hash;
}
