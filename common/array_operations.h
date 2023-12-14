#ifndef ARRAY_OPERATIONS
#define ARRAY_OPERATIONS

// Функция обмена значений под двумя указателями
void Swap(double* ptr1, double* ptr2){
    double buf = *ptr1;
    *ptr1 = *ptr2; 
    *ptr2 = buf;
}

// Функция копирования элементов одномерного массива
void CopyArray(double* initial_array, double* target_array, int size){
    for (int i = 0; i < size; ++i){
        target_array[i] = initial_array[i];
    }
}

// функция слияния двух неубывающих последовательностей
int MergeSorted (double** c, const double* a, const double* b, 
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

#endif