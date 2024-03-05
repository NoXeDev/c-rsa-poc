#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rsa.h"

int main(void) {
    int M = 10331;
    int rsaTest = RSA(9811, 9803, 977, M);

    if(rsaTest == M) {
        printf("RSA test passed\n");
    } else {
        if(rsaTest == -1) {
            printf("RSA test failed: d is not invertible\n");
        } else {
            printf("RSA test failed: %d\n", rsaTest);
        }
    }
}