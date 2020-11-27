#include <bits/stdc++.h>
using namespace std;

int lucas(int n)
{
    if (n < 2)
        return 2 - n;
    else
        return lucas(n - 1) + lucas(n - 2);
}

int main()
{
    cout << lucas(5);
}