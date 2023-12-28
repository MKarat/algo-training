#include <stdio.h>
#include "../common/array_io.h"
#include "../common/array_operations.h"

int main (void){

    double* array = NULL;
    unsigned int array_size = FillArray("input.txt", &array);
    PrintArray("Initial array: ", array, array_size);


    double insert_value = 123;
    unsigned int insert_index = 4;

    Insert(array, &array_size, insert_index, insert_value);
    
    PrintArray("Extended array: ", array, array_size);
    
    free(array);
    return 0;
}
