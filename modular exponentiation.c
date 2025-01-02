#include <stdio.h>

int main() {
    unsigned long long B, N, M, result = 1;

    printf("Enter base (B), exponent (N), and modulus (M): ");
    scanf("%llu %llu %llu", &B, &N, &M);

    B = B % M; // Reduce base modulo M
    while (N > 0) {
        if (N % 2 == 1) {
            result = (result * B) % M; // Multiply result if N is odd
        }
        N /= 2;          // Halve the exponent
        B = (B * B) % M; // Square the base
    }

    // Output the result
    printf("Result: %llu\n", result);

    return 0;
}