#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000  

long long arr[N];  


long long compute_sum_static(int num_threads) {
    long long sum = 0;
    omp_set_num_threads(num_threads);  

    #pragma omp parallel for reduction(+:sum) schedule(static)
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

    long long total_time = 0;
    
    
    for (int i = 0; i < 10; i++) {
        clock_t start = clock(); 
        long long sum = compute_sum();
        clock_t end = clock();  

        long long execution_time = (end - start) * 1000 / CLOCKS_PER_SEC;  
        total_time += execution_time;

        printf("Run %d Execution Time: %lld ms\n", (i + 1), execution_time);
    }

 
    printf("Average Execution Time: %.2f ms\n", (total_time / 10.0));

    return 0;
}
