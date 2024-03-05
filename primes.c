#include "primes.h"

int nextPrime(int previousPrime) {
    int nextPrime = previousPrime + 1;
    int isPrime = 0;

    while(1) {
        isPrime = 1;
        for(int i = 2; i < nextPrime; i++) {
            if(nextPrime % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime == 1) {
            return nextPrime;
        } else {
            nextPrime++;
        }
    }
}

size_t primaryDecomposition(int n, int* res) {
    int primeNbr = 2;
    
    int i = 0;

    while(n != 1) {
        int j = 0;
        while(n % primeNbr == 0) {
            j++;
            n = n / primeNbr;
        }
        if(j > 0) {
            res[i] = primeNbr;
            res[i+1] = j;
            i += 2;
        }
        primeNbr = nextPrime(primeNbr);
    }

    return i;
}