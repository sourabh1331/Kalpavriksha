#include <stdio.h>
unsigned long long modularExponentiation(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent /= 2;
        base = (base * base) % modulus;
    }
    return result;
}
int main() {
    unsigned long long base, exponent, modulus;
    printf("Enter base, exponent, and modulus: ");
    scanf("%llu %llu %llu", &base, &exponent, &modulus);
    unsigned long long result = modularExponentiation(base, exponent, modulus);
    printf("Result: %llu\n", result);

    return 0;
}
