// Программа реализующая алгоритм сортировки пузырьком

#include <stdio.h>
#include "../common/array_io.h"
#include "../common/array_operations.h" 

int main (void){

    // Cчитывание массива из файла input.txt
    double* array = NULL;
    const unsigned int array_size = FillArray("input.txt", &array);
    
    PrintArray("Initial array:", array, array_size);

    for (unsigned int j = 1; j < array_size; ++j){
        for (unsigned int i = 0; i < array_size-j; ++i){
            if (array[i] > array[i+1])
                Swap(&array[i], &array[i+1]);
        }
    }

    PrintArray("Sorted array:", array, array_size);

    free(array); // освобождаем память

    return 0;
}