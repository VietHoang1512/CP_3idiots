#include <bits/stdc++.h>
using namespace std;

int main()
{

    int b = 5, a = 2, c = 2;

    if (b > a && a > c && c > b)

        b = a + 1;

    else

        a = b + 1;
    cout << a + b + c;
}
