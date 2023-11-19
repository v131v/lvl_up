unsigned long long swapDigits(unsigned long long n) {

    unsigned long long last = n % 10llu;
    unsigned long long first = n;
    unsigned long long pw = 1;

    while (first >= 10llu) {
        first /= 10llu;
        pw *= 10llu;
    }

    n += first - last;
    n -= (first - last) * pw;

    return n;
}
