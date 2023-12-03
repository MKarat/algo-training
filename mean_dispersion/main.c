// Программа среднего арифметического и дисперсии последовательности

#include <stdio.h>
#include "../common/array_io.h"

int main (void){

    // Cчитывание массива из файла input.txt
    double* array = NULL;
    const unsigned int array_size = FillArray("input.txt", &array);
    PrintArray("Initial array:", array, array_size);

    // Расчет суммы элементов и суммы квадратов элементов последовательности
    double sum = 0;
    double sum_squere = 0;

    for (unsigned int i = 0; i < array_size; ++i){
        sum += array[i];
        sum_squere += array[i] * array[i]; 
    }
    
    // Расчет среднего арифметического и дисперсии
    double mean = sum / array_size; 
    double dispersion = (sum_squere / array_size) - mean * mean;

    printf("Mean: %lf\n", mean);
    printf("Dispersion: %lf", dispersion);
    
    free(array);
    return 0;
}