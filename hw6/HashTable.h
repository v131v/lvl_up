#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Word.h"
#include "PrimeNumberGenerator.h"

#include <vector>

using namespace std;

struct Value {
    Word word;
    unsigned long count = 0;
};

class HashTable {
private:
    unsigned long _maxLoadFactor = 1;
    unsigned long _bucketsCount = 0;
    unsigned long _size = 0;
    PrimeNumberGenerator* _primes = nullptr;
    mutable vector<vector<Value*>> _data;

public:
    HashTable() = default;

    HashTable(PrimeNumberGenerator* primes);

    ~HashTable();

    const Value* inc(const Word& s);

    Value* get(const Word& s) const;

    void rebalance();

    unsigned long size() const;

    unsigned long capacity() const;
};

#endif // HASHTABLE_H
