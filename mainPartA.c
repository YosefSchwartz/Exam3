#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.c"

#define ARRAY_SIZE 50

int main(){
    printf("Please enter 50 numbers to array: \n");
    int *arr = malloc(ARRAY_SIZE*sizeof(int));
    for(int i =0;i<ARRAY_SIZE;i++){
       scanf("%d",(arr+i));
    }
    
    insertion_sort(arr,ARRAY_SIZE);

    int i;
    for(i = 0;i<ARRAY_SIZE-1;i++){
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+i));

    return 0;
}