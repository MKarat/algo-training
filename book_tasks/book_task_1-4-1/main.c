#include "../../common/array_io.h"

int main (void){

    // Чтение данных из файла
    double* array = NULL;
    unsigned int array_size = 0;
    array_size = FillArray("input.txt", &array);

    PrintArray("Initial array is:", array, array_size);

    // Ввод нового элемента
    double new_element;
    printf("Enter value of new element: \n");
    scanf("%lf", &new_element);

    // Выделим дополнительную память для вставки элемента
    ++array_size;
    array = realloc(array, (array_size)*sizeof(double));

    // Добавим новый элемент в конец массива
    array[array_size - 1] = new_element;

    // Начиная с конца массива последовательно меняем местами соседние элементы
    // пока новый элемент не займёт нужную позицию 
    for (unsigned int i = array_size-1; i > 0; --i){
        
        if (array[i] < array[i-1]){
            double buf = array[i];
            array[i] = array[i-1];
            array[i-1] = buf;
        }
        else break;
    }

    PrintArray("Result array is:", array, array_size);
    free(array);
    return 0;
}