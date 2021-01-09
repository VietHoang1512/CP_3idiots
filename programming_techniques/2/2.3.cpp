#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int get_value(int x, int m = 2, int n = 1, int p = 0)
{
    return m * x * x + n * x + p;
}

int main()
{
    int x;
    scanf("%d", &x);
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c

    //# Nhập 3 số nguyên a, b, c từ bàn phím
    /*****************
    # YOUR CODE HERE #
    *****************/
    cin >> a >> b >> c;
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));

    return 0;
}