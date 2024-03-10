#include "HashTable.h"

HashTable::HashTable() {
    _data.resize(_n);
}

HashTable::HashTable(int m, int n) : _m(m), _n(n) {
    _data.resize(_n);
}

HashTable::~HashTable() {
    for (unsigned long i = 0; i < _data.size(); ++i) {
        for (unsigned long j = 0; j < _data[i].size(); ++j) {
            delete _data[i][j];
        }
    }
}

Value* HashTable::inc(const Word& s) {
    auto target = get(s);

    if (target != nullptr) {
        target->count++;
        return target;
    }

    unsigned long hash = s.hash() % _n;
    if (_data[hash].size() + 1 >= _m) {
        rebalance();
        hash = s.hash() % _n;
    }

    Word strCopy(s);
    auto pr = new Value{strCopy, 1};
    _data[hash].push_back(pr);
    _size++;

    return pr;
}

Value* HashTable::get(const Word& s) const {
    unsigned long hash = s.hash() % _n;

    for (unsigned long i = 0; i < _data[hash].size(); ++i) {
        if (_data[hash][i]->word == s) {
            swap(_data[hash][i], _data[hash][0]);
            return _data[hash][0];
        }
    }
    return nullptr;
}

void HashTable::rebalance() {
    _n <<= 1;
    _m++;
    _data.reserve(_n);

    for (unsigned long i = 0; i < _data.size(); ++i) {
        for (unsigned long j = 0; j < _data[i].size(); ++j) {
            unsigned long hash = _data[i][j]->word.hash() % _n;

            if (hash != i) {
                _data[hash].push_back(_data[i][j]);
                swap(_data[i][j], _data[i][_data[i].size()-1]);
                _data[i].pop_back();
            }
        }
    }
}

unsigned long HashTable::size() const {
    return _size;
}
