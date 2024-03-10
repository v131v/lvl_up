#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Word.h"

#include <vector>

using namespace std;

struct Value {
    Word word;
    int count;
};

class HashTable {
    unsigned long _m = 10;
    unsigned long _n = 1<<_m;
    unsigned long _size = 0;
    mutable vector<vector<Value*>> _data;
public:
    HashTable();

    HashTable(int m, int n);

    ~HashTable();

    Value* inc(const Word& s);

    Value* get(const Word& s) const;

    void rebalance();

    unsigned long size() const;
};

#endif // HASHTABLE_H
