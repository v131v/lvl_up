#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "HashTable.h"
#include "PrimeNumberGenerator.h"

#include <array>
#include <vector>

class WordCounter {
private:
    static constexpr int _lettersCount = 26;
    unsigned long _size = 0;
    std::array<std::vector<HashTable>, _lettersCount> _data = {};
    PrimeNumberGenerator* _primes;

public:
    WordCounter();

    ~WordCounter();

    void inc(const Word& s);

    int get(const Word& s) const;

    unsigned long size() const;
};

#endif // WORDCOUNTER_H
