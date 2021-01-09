#include <stdio.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    if(n>1)
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(*(a+j)<*(a+i))
                {
                    tmp=*(a+j);
                    *(a+j)=*(a+i);
                    *(a+i)=tmp;
                }
            }
        }
    }
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    delete [] a;
    return 0;
}