#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int isPrime(long long a)
{
    for (long long i = 2; i <= sqrt(a); i++)
        if ((long long)a % i == 0)
            return 0;
    return 1;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long n;
    cin >> n;

    if (n < 4)
    {
        cout << 1;
    }
    else if (!(n % 2))
    {
        cout << 2;
    }
    else
    {
        if (isPrime(n))
        {
            cout << 1;
        }
        else if (isPrime(n - 2))
        {
            cout << 2;
        }
        else
            cout << 3;
    }
}
