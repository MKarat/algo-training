#include <stdio.h>
#include <stdlib.h>

#include "../common/array_input.h"


// Функция заменяет все положительные элементы массива на его сумму с соседними
// элементами деленную на 3 (за исключением первого и последнего элемента)
void Transform(float* array, const int array_size);

int main()
{
    // Чтение данных из файла
    float* array = NULL;
    int array_size = 0;
    array_size = FillArray("input.txt", &array);

    // Печать полученных данных
    printf("Array size = %i \n", array_size);
    printf("Initial array is: \n");
    for (int i = 0; i < array_size; ++i){
        printf("%f ",array[i]); 
    }
    printf("\n");
    
    // Преобразование массива
    Transform(array, array_size);
    
    // Печать результата
    printf("Result array is: \n");
    for (int i = 0; i < array_size; ++i){
        printf("%f ",array[i]); 
    }
    printf("\n");
        
    free(array); // освобождение памяти
}

void Transform(float* array, const int array_size){
    
    float current = 0;      // Переменная для сохранения текущего элемента перед
                            // его изменением 
    
    float previous = array[0];  // Переменная для сохранения предыдущего 
                                // неизмененного элемента

    // Цикл по элементам массива со второго по предпоследний
    for (int i = 1; i < array_size-1; ++i){
       
        current = array[i]; // сохранение текущего элемента
                
        // изменению подлежат только положительные элементы
        if (array[i] > 0)

            // используем именно сохраненный вариант предыдущего элемента,
            // т.к. его значение могло измениться
            array[i] = (previous + array[i] + array[i+1])/3;                

        previous = current; // сохраняем неизмененное значение текущего элемента
    }
}
