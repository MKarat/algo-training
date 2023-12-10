#include <stdio.h>

#include "../common/array_io.h"
#include "../common/array_operations.h"

int main (void){

    double* array = NULL;
    const unsigned int size = FillArray("input.txt", &array);

    PrintArray("Initial array:", array, size);

    double* tmp_array = NULL;

    for (unsigned int i = 1; i < size; i *= 2){
        for (unsigned int j = 0; j <= size - 2 * i; j += 2 * i){
            
            MergeSorted(&tmp_array, &array[j], &array[j+i], i, i);
            PrintArray("Merged array:", tmp_array, 2 * i);            
            
            for (unsigned int k = j; k < j + 2 * i ; ++k){
                array[k] = tmp_array[k-j];
            }
        }
    }

    PrintArray("Sorted array:", array, size);

    free(tmp_array);
    free(array);
    return 0;

}