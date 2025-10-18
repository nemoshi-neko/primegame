#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 10000 // Define a maximum size for the array

// Function to check if a number is a power of 2
bool is_pow2(unsigned int x) {
    return x && !(x & (x - 1));
}

// Function to generate the sequence
void generate_sequence(double n, int* k, int* count) {
    static const int c[] = {17, 78, 19, 23, 29, 77, 95, 77, 1, 11, 13, 15, 1, 55};
    static const int m[] = {91, 85, 51, 38, 33, 29, 23, 19, 17, 13, 11, 2, 7, 1}; 

    for (int i = 0; i < 14 && *count < MAX_SIZE; i++) { // Combined loop condition
        double tmp = n * (double)c[i] / m[i]; 
        if (tmp == (int)tmp) {
            k[*count] = (int)tmp;
            (*count)++;
            generate_sequence(tmp, k, count);
        }
    }
}

int main() {
    double n = 2;
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
    printf("\n");

    return 0;
}