#include <stdio.h>
#include <omp.h>

int main() {
    printf("Before parallel region\n");

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf("Thread %d: Before the barrier\n", thread_id);

        // Barrier
        #pragma omp barrier

        // Code executed after all threads reach the barrier
        printf("Thread %d: After the barrier\n", thread_id);

        // Final synchronization for all threads before exit
        #pragma omp barrier
        if (thread_id == 0) {
            printf("All %d threads have synchronized at the second barrier.\n", num_threads);
        }
    }

    printf("After parallel region\n");
    return 0;
}