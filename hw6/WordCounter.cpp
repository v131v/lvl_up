#include "WordCounter.h"
#include "PrimeNumberGenerator.h"

#include <iostream>

WordCounter::WordCounter() {
    _primes = new PrimeNumberGenerator(1e7);

    for (unsigned long i = 0; i < _lettersCount; ++i) {
        _data[i].reserve(Word::minCapacity);

        for (unsigned long j = 0; j < Word::minCapacity; ++j) {
            _data[i].push_back({ _primes });
        }
    }
}

WordCounter::~WordCounter() {
    delete _primes;
}

void WordCounter::inc(const Word& s) {
    if (_data[s[0]-'a'].size() < s.size()) {
        _data[s[0]-'a'].resize(s.size(), { _primes });
    }

    const int cnt = _data[s[0]-'a'][s.size()-1].inc(s)->count;
    if (cnt == 1) {
        _size++;
    }
}

int WordCounter::get(const Word& s) const {
    if (_data[s[0]-'a'].size() < s.size()) {
        return 0;
    }

    const auto target = _data[s[0]-'a'][s.size()-1].get(s);
    if (target == nullptr) {
        return 0;
    }

    return target->count;
}

unsigned long WordCounter::size() const {
    return _size;
}
