#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 550
/** Define a maximum size for the array.
 * The calculation will probably go awry midway due to the limitations of floating point numbers.
 * So, to avoid overflow, I set a limit that came to mind. (n <= 550)
 */

// Function to check if a number is a power of 2
bool is_pow2(unsigned int x) {
    return x && !(x & (x - 1));
}

// Function to generate the sequence
void generate_sequence(long long n, int* k, int* count) {
    static const int c[] = {17, 78, 19, 23, 29, 77, 95, 77, 1, 11, 13, 15, 1, 55};
    static const int m[] = {91, 85, 51, 38, 33, 29, 23, 19, 17, 13, 11, 2, 7, 1}; 

    for (int i = 0; i < 14 && *count < MAX_SIZE; i++) { // Combined loop condition
        long long numerator = n * c[i];
        
        if (numerator % m[i] == 0) {
            long long next_n = numerator / m[i];

            if (next_n > 0 && next_n <= 2147483647) {
                k[*count] = (int)next_n;
                (*count)++;
                generate_sequence(next_n, k, count);
            }
        }
    }
}

int main() {
    long long n = 2;
    int k[MAX_SIZE];
    int count = 0;

    k[count++] = n;
    generate_sequence(n, k, &count); 

    // Find and print powers of 2 in the sequence
    printf("Powers of 2:\n");
    for (int i = 0; i < count; i++) {
        if (is_pow2(k[i])) {
            printf("%d, ", (int)log2(k[i]));
        }
    }
    printf("\nNumbers excluding 1 are prime numbers.");

    return 0;
}