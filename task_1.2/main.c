#include <stdio.h>

int main (){

    FILE* input_file = fopen("test_3.txt", "r");

    int a1 = 0;
    int a2 = 0;

    fscanf(input_file, "%i", &a1);
    fscanf(input_file, "%i", &a2);

    if (a1 == 0 || a2 == 0){
        printf("The sequence is't geomtric\n");
        return 0;
    }

    int q1 = a2 / a1;

    int ai = 0;
    int a_previous = a2;

    int i = 3;

    while (fscanf(input_file, "%i", &ai) == 1){
        
        if (ai != a1*q1*(i-1)){
            printf("The sequence is't geometric\n");
            return 0;
        }
        ++i;    
    }

    printf("a1 = %i, q = %i \n", a1, q1);

    return 0;
} 