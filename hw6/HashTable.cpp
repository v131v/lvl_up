#include "HashTable.h"
#include "PrimeNumberGenerator.h"

#include <iostream>

HashTable::HashTable(PrimeNumberGenerator* primes)
    : _maxLoadFactor(1)
    , _bucketsCount(13)
    , _primes(primes)
{
    _data.resize(_bucketsCount);
}

HashTable::~HashTable() {
    for (unsigned long i = 0; i < _data.size(); ++i) {
        for (unsigned long j = 0; j < _data[i].size(); ++j) {
            delete _data[i][j];
        }
    }
}

const Value* HashTable::inc(const Word& s) {
    Value* target = get(s);

    if (target != nullptr) {
        target->count++;
        return target;
    }

    unsigned long hash = s.hash() % _bucketsCount;
    if ((_size + 1) > _maxLoadFactor * _bucketsCount) {
        rebalance();
        hash = s.hash() % _bucketsCount;
    }

    Word strCopy(s);
    auto pr = new Value{ strCopy, 1 };
    _data[hash].push_back(pr);
    _size++;

    return pr;
}

Value* HashTable::get(const Word& s) const {
    using std::swap;

    unsigned long hash = s.hash() % _bucketsCount;

    for (unsigned long i = 0; i < _data[hash].size(); ++i) {
        if (_data[hash][i]->word == s) {
            swap(_data[hash][i], _data[hash][0]);
            return _data[hash][0];
        }
    }
    return nullptr;
}

void HashTable::rebalance() {
    using std::swap;

    const unsigned long newBucketsCount = _primes->upperBound(_bucketsCount * 2);
    vector<vector<Value*>> newBuckets;
    newBuckets.resize(newBucketsCount, {});

    for (unsigned long i = 0; i < _bucketsCount; ++i) {
        for (unsigned long j = 0; j < _data[i].size(); ++j) {
            unsigned long hash = _data[i][j]->word.hash() % newBucketsCount;
            newBuckets[hash].push_back(_data[i][j]);
        }
    }

    _bucketsCount = newBucketsCount;
    _data = newBuckets;
}

unsigned long HashTable::size() const {
    return _size;
}

unsigned long HashTable::capacity() const {
    return _bucketsCount;
}
