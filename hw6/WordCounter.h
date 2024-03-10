#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "HashTable.h"
#include <array>

using namespace std;

class WordCounter {
    static constexpr int _lettersCount = 26;
    unsigned long _size = 0;
    array<vector<HashTable>, _lettersCount> _data;
public:
    WordCounter();

    ~WordCounter();

    void inc(const Word& s);

    int get(const Word& s) const;

    unsigned long size() const;
};

#endif // WORDCOUNTER_H
