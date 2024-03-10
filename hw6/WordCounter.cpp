#include "WordCounter.h"

WordCounter::WordCounter() {
    for (int i = 0; i < _lettersCount; ++i) {
        _data[i].resize(Word::minCap);
    }
}

WordCounter::~WordCounter() {}

void WordCounter::inc(const Word& s) {
    if (_data[s[0]-'a'].size() < s.length()) {
        _data[s[0]-'a'].resize(s.length());
    }

    const int cnt = _data[s[0]-'a'][s.length()-1].inc(s)->count;
    if (cnt == 1) {
        _size++;
    }
}

int WordCounter::get(const Word& s) const {
    if (_data[s[0]-'a'].size() < s.length()) {
        return 0;
    }

    const auto target = _data[s[0]-'a'][s.length()-1].get(s);
    if (target == nullptr) {
        return 0;
    }

    return target->count;
}

unsigned long WordCounter::size() const {
    return _size;
}
