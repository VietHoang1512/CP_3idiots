#include<stdio.h>

int counteven(int* arr, int size){
    int count = 0;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int i;
    for (i=0;i<size;++i){
        if(!(arr[i]%2)){
            count++;
        }
    }
    return count;    
}

// int main(){
//     int a[10] = {12,434,-14,4,12,56,1,75,7,-9};
//     printf("%d\n", counteven(a, 10));
//     return 0;
// }