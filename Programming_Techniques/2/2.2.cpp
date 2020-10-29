#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int tmp;

void triSwap(int &a, int &b, int &c)
{
        tmp = a;
        a = b;
        b = c;
        c = tmp;
}

int main()
{
    cin >> x >> y >> z;

    //# Nhập 3 số nguyên
    /*****************
    # YOUR CODE HERE #
    *****************/

    printf("Before: %d, %d, %d\n", x, y, z);
    triSwap(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}