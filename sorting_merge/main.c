#include <stdio.h>

#include "../common/array_io.h"
#include "../common/array_operations.h"


int MergeSort(double* array, unsigned int size){


    // Условие прекращения рекурсивного деления
    if (size == 1){
        return 1;
    }

    //Разделим массив на две части
    unsigned int left_array_size = size/2;
    double left_array[left_array_size];
    CopyArray(array, left_array, left_array_size);

    unsigned int right_array_size = size-size/2;
    double right_array[right_array_size];
    CopyArray(&array[size/2], right_array, right_array_size);

    // Продолжим деление массива рекурсивно
    MergeSort(left_array, left_array_size);
    MergeSort(right_array, right_array_size);
    
    // Выполним слияние левого и правого массива
    double* merged_array = NULL;
    MergeSorted(&merged_array, left_array, right_array, 
                        left_array_size, right_array_size);
    
    // Скопируем результат слияния в исходный массив
    CopyArray(merged_array, array, left_array_size+right_array_size);

    free(merged_array);
    return size;
}


int main (void){

    double* array = NULL;
    const unsigned int size = FillArray("input.txt", &array);

    PrintArray("Initial array:", array, size);

    MergeSort(array, size);

    // double* tmp_array = NULL;

    // for (unsigned int i = 1; i < size; i *= 2){
    //     for (unsigned int j = 0; j <= size - 2 * i; j += 2 * i){
            
    //         MergeSorted(&tmp_array, &array[j], &array[j+i], i, i);
    //         PrintArray("Merged array:", tmp_array, 2 * i);            
            
    //         for (unsigned int k = j; k < j + 2 * i ; ++k){
    //             array[k] = tmp_array[k-j];
    //         }
    //     }
    // }

    PrintArray("Sorted array:", array, size);

    //free(tmp_array);
    free(array);
    return 0;

}