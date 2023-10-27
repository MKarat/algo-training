#include <stdio.h>

int main () {

    FILE* input_file = fopen("input_test_true.txt" ,"r");

 
    int first_number = 0;
    int second_number = 0;
    fscanf(input_file, "%i", &first_number);
    fscanf(input_file, "%i", &second_number);

    int delta = second_number - first_number;
   
    int current_number = 0;
    int i = 3;
    
    while(fscanf(input_file, "%i", &current_number) == 1){
        
        int ai = first_number+(i-1)*delta;
        
        if (ai != current_number){
            printf("NO!\n");
            return 0;
        }
        
        ++i;
    }
    
    fclose(input_file);
    
    printf("YES! step=%i\n", delta);
    
    return 0;
}