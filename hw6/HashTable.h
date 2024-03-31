#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Word.h"
#include "PrimeNumberGenerator.h"

#include <vector>

using namespace std;

struct Value {
    Word word;
    int count;
};

class HashTable {
private:
    unsigned long _maxLoadFactor = 0;
    unsigned long _bucketsCount = 0;
    unsigned long _size = 0;
    const PrimeNumberGenerator* const _primes = nullptr;
    mutable vector<vector<Value*>> _data;

public:
    HashTable();

    HashTable(const PrimeNumberGenerator* const primes);

    ~HashTable();

    Value* inc(const Word& s);

    Value* get(const Word& s) const;

    void rebalance();

    unsigned long size() const;
};

#endif // HASHTABLE_H
