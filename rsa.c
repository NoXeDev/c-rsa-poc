#include "rsa.h"
#include "primes.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int phi(int n) {
    int* res = (int*)malloc(100 * sizeof(int));
    size_t decomp = primaryDecomposition(n, res);
    res = realloc(res, decomp * sizeof(int));

    int x = 1;
    for(int i = 0; i < decomp; i+=2) {
        x = x * (pow(res[i], res[i+1]) - pow(res[i], res[i+1]-1));
    }
    free(res);

    return x;
}

int invmod(int nbr, int modulo) {
    int l1[3] = {nbr, 1, 0};
    int l2[3] = {modulo, 0, 1};

    while(l2[0] != 0) {
        int q = ediv(l1[0], l2[0]);
        int tmp[3] = {l2[0], l2[1], l2[2]};
        for(int i = 0; i < 3; i++) {
            l2[i]=l1[i]-q*l2[i];
        }
        for(int i = 0; i < 3; i++) {
            l1[i] = tmp[i];
        }
    };
    if(l1[0] != 1) {
        return -1;
    }
    return mod(l1[1], modulo);
}

int modpow(long long base, long long exp, long long modulo) {
    long long res = 1;
    long long basepow = base;
    for(int binpow = 0; pow(2, binpow) < exp; binpow++) {
        int mask = (int)pow(2, binpow);
        res = (exp & mask) > 0 ? (mod(res * basepow, modulo)) : res;
        basepow = mod(pow(basepow, 2), modulo);
    }
    return (int)res;
}

int RSA(int n, int p, int e, int M) {
    int np = n * p;
    printf("np: %d\n", np);
    int d = invmod(e, phi(np));
    printf("phi np: %d\n", phi(np));
    printf("d: %d\n", d);
    if(d == -1) {
        return -1;
    }

    int Mp = modpow(M, e, np);
    printf("modpow(%d, %d, %d): %d\n", M, e, np, modpow(M, e, np));

    int C = modpow(Mp, d, np);
    printf("modpow(%d, %d, %d): %d\n", Mp, d, np, modpow(Mp, d, np));

    return C;
}