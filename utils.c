#include "utils.h"

void printPrimaryDecomposition(int* res, size_t size) {
    for(int i = 0; i < size; i+=2) {
        printf("%d^%d", res[i], res[i+1]);
        if(i+2 < size) {
            printf(" * ");
        }
    }
    printf("\n");
}

int ediv(int a, int b) {
    int r = a % b;
    if (r < 0) r += abs(b);
    return (a - r) / b;
}

int mod(long long a, long long b) {
    long long r = a % b;
    return (int)(r < 0 ? r + b : r);
}