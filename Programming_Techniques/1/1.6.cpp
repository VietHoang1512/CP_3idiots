#include<stdio.h>

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++; r--;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while(l<r){
        tmp = *(arr+l);
        *(arr+l) = *(arr+r);
        *(arr+r) = tmp;
        l++; r--;
    }
}



// int main(){
//     return 0;
// }