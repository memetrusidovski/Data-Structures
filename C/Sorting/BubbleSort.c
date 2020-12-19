#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    int sort [] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};

    bool swap = true;
    int index = sizeof(sort)/sizeof(int);

    while(swap){
        swap = false;
        for(int i = 0; i < index; i++){
            if(sort[i] > sort[i+1]){
                int temp = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = temp;
                swap = true;
            }
        }
    }

    for(int i = 0; i <= index; i++)
        printf("%d, ", sort[i]);
}