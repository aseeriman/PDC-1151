#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000 

long long arr[N]; 


long long compute_sum() {
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

