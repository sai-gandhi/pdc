#include <omp.h>
#include <stdio.h>
int main() {
 int x = 10;
 #pragma omp parallel private(x)
 {
 x = omp_get_thread_num();
 printf("Thread %d has x = %d\n", omp_get_thread_num(), x);
 }
 return 0;
}
