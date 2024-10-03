#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100

int main() {
    int NUMHILO = 4;
    int array[SIZE];
    int max_val, min_val;
    double avg_val;
    int sum = 0;

    #pragma omp parallel num_threads(NUMHILO)
    {
        int thread_num = omp_get_thread_num();
        int inicio =  25 * thread_num;
        int fin =  (25 * (thread_num + 1)) - 1;
        printf("Hola desde el hilo %d me encargo de los valores de %d hasta %d\n", thread_num , inicio , fin);
        for (int i = inicio; i < fin; i++) {
            array[i] = rand() % 1000;
        }
    }

    max_val = array[0];
    min_val = array[0];

    #pragma omp parallel for reduction(+:sum) reduction(max:max_val) reduction(min:min_val)
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > max_val) max_val = array[i];
        if (array[i] < min_val) min_val = array[i];
        sum += array[i];
    }

    avg_val = sum / (double)SIZE;

    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);
    printf("Average value: %.2f\n", avg_val);

    return 0;
}