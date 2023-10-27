#include <stdio.h>

#include "../common/array_input.h"

void PrintArray(char* message, double* array, int array_size){

    printf("%s", message);
    printf("\n");
    for (int i = 0; i < array_size; ++i){
        printf("%f ",array[i]); 
    }
    printf("\n");
}

int FindMax (double* array, int array_size){
    
    int j_max = 0;
    double max_el = array[j_max];

    for (int j = 1; j < array_size ; ++j){
        if (array[j] > max_el){
            j_max = j;
            max_el = array[j];
        }
    }

    return j_max;
}



int main (void){

    // Чтение данных из файла
    double* array = NULL;
    int array_size = 0;
    array_size = FillArray("input.txt", &array);


    PrintArray("Initial array is:", array, array_size);

    for (int i = array_size-1; i >= 0; --i){
        
        int j_max = FindMax(array, i+1);

        double tmp = array[i];
        array[i] = array[j_max];
        array[j_max] = tmp;        
    }

    PrintArray("Sorted array is:", array, array_size);

    free(array);
    return 0;
}