#include <stdio.h>
#include <omp.h>

int main() {
    printf("Before parallel region\n");

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        // Code block executed by only one thread
        #pragma omp single
        {
            printf("This section is executed by thread %d\n", thread_id);
        }

        // Code executed by all threads
        printf("Thread %d: executing the rest of the parallel region\n", thread_id);
    }

    printf("After parallel region\n");

    return 0;
}
