#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_num = omp_get_thread_num();
        if (thread_num % 2 == 0) {
            printf("Hola desde el hilo par %d\n", thread_num);
        } else {
            printf("Hola desde el hilo impar %d\n", thread_num);
        }
    }
    return 0;
}