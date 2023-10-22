#include <math.h>
#include <stdio.h>

// Определить является ли натуральное число палиндромом
// Пример 12321, 145541
//        43210
int main()
{
    unsigned long long x;

    printf("enter x\n");
    scanf("%llu", &x);

    // (x / 10^i) % 10
    // i, len-i-1

    unsigned long long len = ceil(log10(x));

    for (unsigned long long i = 0; i < len/2; i++) {
        const unsigned long long right = (unsigned long long)(x / pow(10, i)) % 10;
        const unsigned long long left = (unsigned long long)(x / pow(10, len - i - 1)) % 10;

        if (left != right) {
            printf("not a palindrome\n");
            return 0;
        }
    }

    printf("palindrome\n");

    return 0;
}
