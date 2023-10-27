#include "../../common/array_io.h"

int main (void){

    // Чтение данных из файла
    double* array = NULL;
    unsigned int array_size = 0;
    array_size = FillArray("input.txt", &array);

    PrintArray("Initial array is:", array, array_size);

    // Ввод элемента для поиска
    double element;
    printf("Enter value of new element: \n");
    scanf("%lf", &element);

    unsigned int left_boarder = 0;
    unsigned int right_boarder = array_size-1;
    unsigned int midle = (right_boarder + left_boarder)/2;

    // Проверка принадлежности элемента интервалу между min и max массива
    if ((element < array[left_boarder]) || (array[right_boarder] < element)){
        printf("Element is't in array \n");
        return 0;
    }

    // Проверка элемента на равенство граничным значениям
    if ((element == array[left_boarder]) || (array[right_boarder] == element)){
        printf("Element is in array \n");
        return 0;
    }

    // Метод бинарного поиска
    while ((right_boarder-left_boarder) > 1) {
        
        if (element < array[midle]){
            right_boarder = midle;
        } 
        else if (element > array[midle]){
            left_boarder = midle;
        } else {
            printf("Element is in array! \n");
            return 0;
        }

        midle = (right_boarder + left_boarder) / 2;
    }

 
    printf("Element is't in array \n");
    free(array);
    return 0;
}