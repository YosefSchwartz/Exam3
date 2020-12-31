# include <stdio.h>

void shift_element(int *arr, int i){
    //printf("size of array shift - %d",(n));
    for(int j = i;j>0;j--)
        *(arr+j) = *(arr+(j-1));
}

void insertion_sort(int *arr , int len){
    for(int i=0;i<len;i++){
        int num = *(arr+i);
        int j = i;
        while(*(arr+i)<*(arr+j-1)&&j>0)
            j--;

        if(i!=j){
            shift_element(arr+j,i-j);
            *(arr+j)=num;
        }       
    }

}
