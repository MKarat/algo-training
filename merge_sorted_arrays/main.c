// Программа слияния двух неубывающих последовательностей

#include <stdio.h>
#include "../common/array_io.h"

// функция слияния двух неубывающих последовательностей
int merge_sorted (double** c, const double* a, const double* b, 
                            unsigned int na, unsigned int nb);


int main (void){

    // Cчитывание массива A из файла input.txt
    double* array_A = NULL;
    const unsigned int size_A = FillArray("input_a.txt", &array_A);
    PrintArray("Initial array A:", array_A, size_A);

    // Cчитывание массива B из файла input.txt
    double* array_B = NULL;
    const unsigned int size_B = FillArray("input_b.txt", &array_B);
    PrintArray("Initial array B:", array_B, size_B);
       
    double* array_C = NULL;
    unsigned int size_C = 0;
    size_C = merge_sorted(&array_C, array_A, array_B, size_A, size_B);

    PrintArray("Merged array C:", array_C, size_C);    

    free(array_A);
    free(array_B);
    free(array_C);
    return 0;
}

// функция слияния двух неубывающих последовательностей
int merge_sorted (double** c, const double* a, const double* b, 
                    unsigned int size_a, unsigned int size_b){

    unsigned int size_c = size_a + size_b; // размер объединенного массива

    *c = (double*)malloc(size_c * sizeof(double)); // выделение требуемой памяти

    int i = 0; // итератор для массива а
    int j = 0; // итератор для массива b
    
    // цикл заполнения массива c
    for (unsigned int k = 0; k < size_c; ++k){
        
        // контроль достижения конца массива а
        if (i+1 > size_a){
            (*c)[k] = b[j]; // оставшиеся элементы берём из массива b
            ++j;
            continue;
        }

        // контроль достижения конца массива b
        if (j+1 > size_b){
            (*c)[k] = a[i]; // оставшиеся элементы берём из массива a
            ++i;
            continue;
        }

        // выбор минимального элемента из текущих a[i] и b[j] в качестве
        // очередного элемента для массива c
        if (a[i] < b[j]){
            (*c)[k] = a[i];
            ++i;
        } else {
            (*c)[k] = b[j];
            ++j;
        }        
    }
    
    return size_c;
}