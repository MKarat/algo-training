#include <stdio.h>
#include <stdlib.h>

void Transform (int array_size, float* array){
    
    float previous = array[0];

    for (int i = 1; i < array_size-1; ++i){
        
        float current = array[i];

        if (array[i]>0)
            array[i] = (previous + array[i] + array[i+1])/3;

        previous = current;    
    }
}

int FillArray(char* file_name, float** array_ptr){
    
    FILE* input_file = NULL;

    input_file = fopen(file_name, "r");

    if (input_file == NULL){
        printf("File wasn't opened");
        exit(1);
    }

    float input_element = 0;
    int array_size = 0;

    while (fscanf(input_file, "%f", &input_element) == 1)
        ++array_size;
    
    *array_ptr = (float*)malloc(array_size*sizeof(float));
    
    rewind(input_file);

    for (int i = 0; i < array_size; ++i){
        fscanf(input_file, "%f", &input_element);
        (*array_ptr)[i] = input_element;
    }

    fclose(input_file);
    return array_size;
}


int main (void) {

    float* array = NULL;

    int array_size = FillArray("input.txt", &array);
        

    printf("%i \n", array_size);

    Transform(array_size, array);


    for (int i = 0; i < array_size; ++i){
        printf("%f ", array[i]);
    } 
    
    printf("\n");

    free(array);
    return 0;
}