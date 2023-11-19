#include <math.h>

unsigned long long numlen(unsigned long long n) {
    return floor(log10(n)) + 1;
}
