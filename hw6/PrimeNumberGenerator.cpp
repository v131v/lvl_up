#include "PrimeNumberGenerator.h"

PrimeNumberGenerator::PrimeNumberGenerator(unsigned long n) {
    _lp.resize(n + 1, 0);
    for (unsigned long i = 2; i <= n; ++i) {
        if (_lp[i] == 0) {
            _lp[i] = i;
            _primeNumbers.push_back(i);
        }

        for (const unsigned long p: _primeNumbers) {
            if (p > _lp[i] || p*i > n) {
                break;
            }
            _lp[p*i] =p;
        }
    }
}

unsigned long PrimeNumberGenerator::upperBound(unsigned long x) const {
    if (maxValue() <= x) return 0;

    int left = 0;
    int right = _primeNumbers.size();
    int m = (right - left) / 2 + left;

    while (right - left > 1) {
        if (_primeNumbers[m] > x) {
            right = m;
        } else {
            left = m;
        }

        m = (right - left) / 2 + left;
    }

    if (_primeNumbers[left] > x) return _primeNumbers[left];
    return _primeNumbers[right];
}

unsigned long PrimeNumberGenerator::maxValue() const {
    return _primeNumbers[_primeNumbers.size() - 1];
}
