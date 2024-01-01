#include <stdio.h>
#include "../common/array_io.h"
#include "../common/array_operations.h"

int main (void){

    double* array = NULL;
    unsigned int array_size = FillArray("input.txt", &array);
    PrintArray("Initial array: ", array, array_size);

    Insert(array, &array_size, 4, 123);
    
    PrintArray("Array after insertion: ", array, array_size);

    Delete(array, &array_size, 4);

    PrintArray("Array after deletion: ", array, array_size);
    
    free(array);
    return 0;
}
