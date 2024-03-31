#ifndef PRIMENUMBERGENERATOR_H
#define PRIMENUMBERGENERATOR_H

#include <vector>

class PrimeNumberGenerator {
private:
    std::vector<unsigned long> _lp;
    std::vector<unsigned long> _primeNumbers;

public:
    PrimeNumberGenerator(unsigned long n);

    unsigned long upper_bound(unsigned long x) const;

    unsigned long maxValue() const;
};

#endif // PRIMENUMBERGENERATOR_H
