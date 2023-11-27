#ifndef ARRAY_OPERATIONS
#define ARRAY_OPERATIONS

// Функция обмена значений под двумя указателями
void Swap(double* ptr1, double* ptr2){
    double buf = *ptr1;
    *ptr1 = *ptr2; 
    *ptr2 = buf;
}

#endif