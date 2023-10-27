#ifndef ARRAY_IO
#define ARRAY_IO

#include <stdio.h>
#include <stdlib.h>

// Функция заполняет одномерный массив данными из файла 
// и возвращает его длину
// ВАЖНО! Необходимо выполнить free после использования array
int FillArray(const char* file_name, double** array){

        // Открытие файла на чтение
    FILE* input_file = NULL;
    input_file = fopen(file_name, "r");
    
    // Проверка успешности открытия файла
    if (input_file == NULL) {
        printf("Input file wasn't open");
        exit(1);
    }

    double el = 0;
    unsigned int array_size = 0;

    // Подсчет количества элементов в файле
    while (fscanf(input_file, "%lf", &el) == 1) ++array_size;

    // Выделение памяти 
    *array = (double*)malloc(array_size*sizeof(double));
   
    rewind(input_file);     // смещение курсора в начало файла
    
    // Заполнение массива данными из файла
    for (unsigned int i= 0; i < array_size; ++i){
        fscanf(input_file, "%lf", &el); 
        (*array)[i] = el;
    }

    fclose(input_file);  // закрытие файла

    return (int)array_size;
}


void PrintArray(char* message, double* array, int array_size){

    printf("%s", message);
    printf("\n");
    for (int i = 0; i < array_size; ++i){
        printf("%f ",array[i]); 
    }
    printf("\n");
}

#endif
