#include <stdio.h>

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;

    /*****************
    # YOUR CODE HERE #
    *****************/
    for(int i=0; i<size;++i){
        if(a[i]>*max){
            max = (a+i);
        }
    }
    return max;
}

// int main(){
//     double a[10]= {23.4, 14.43, 34.5, -3.4, 5.65, 2, 43.324, 454.4542, 54, -5425};
//     printf("\t%p\t%lf\n", maximum(a,10), *maximum(a,10));
//     return 0;
// }