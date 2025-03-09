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

int main() {
    // Initialize array
    for (long long i = 0; i < N; i++) {
        arr[i] = i;
    }

    int num_threads = 4;
    long long total_time = 0;

    
    for (int i = 0; i < 10; i++) {
        double start = omp_get_wtime();
        long long sum = compute_sum_dynamic(num_threads);
        double end = omp_get_wtime();
        total_time += (end - start) * 1000;
        printf("Run %d Execution Time: %.2f ms\n", i + 1, (end - start) * 1000);
    }

    
    printf("Average Execution Time (Dynamic Scheduling): %.2f ms\n", total_time / 10.0);

    return 0;
}