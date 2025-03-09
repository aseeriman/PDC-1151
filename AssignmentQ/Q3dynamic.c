#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000  

long long arr[N];  


long long compute_sum_dynamic(int num_threads) {
    long long sum = 0;
    omp_set_num_threads(num_threads);  
    
    #pragma omp parallel for reduction(+:sum) schedule(dynamic)
    for (long long i = 0; i < N; i++) {
        sum += arr[i];
    }

    return sum;
}