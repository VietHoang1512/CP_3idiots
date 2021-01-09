#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    return float(sqrt(double(x*x + y*y)));
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}