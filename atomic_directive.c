#include <stdio.h>
#include <omp.h>

int main() {
    int shared_sum = 0;

    printf("Initial value of shared_sum: %d\n", shared_sum);

    // Parallel region
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        // Each thread updates the shared variable atomically
        #pragma omp atomic
        shared_sum += thread_id;

        printf("Thread %d: Added its ID to shared_sum\n", thread_id);
    }

    printf("Final value of shared_sum: %d\n", shared_sum);

    return 0;
}