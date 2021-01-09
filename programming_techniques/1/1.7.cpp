#include<stdio.h>
int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //#Allocate memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    int min;
    for(int i=0;i<n;++i){
        min = i;
        for(int j=i+1;j<n;++j){
            if(*(a+min)>*(a+j)) min = j;
        }
        if(min != i){
            tmp = *(a+i);
            *(a+i)=*(a+min);
            *(a+min) = tmp;
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
    return 0;
}