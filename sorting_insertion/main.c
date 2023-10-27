#include "../common/array_io.h" 



int main(void){
    
    double* array = NULL;
    int array_size = FillArray("input.txt", &array);
    PrintArray("Initial array:", array, array_size);


    for (int i = 1; i < array_size; ++i)
    {
        for (int j = i; j > 0 ; --j){
            
            if (array[j] < array[j-1]) {
                double buf = array[j];
                array[j] = array[j-1];
                array[j-1] = buf;
                PrintArray("Current array:", array, array_size);
            } else break;
        }
    }


    PrintArray("Sorted array:", array, array_size);

    free(array);
    return 0;
}