#include <bits/stdc++.h>

using namespace std;
int N, P, p;

int max_prime_div(int a)
{
    int res = 1;
    while (a % 2 == 0)
    {
        res = 2;
        a /= 2;
    }
    // cout << a << endl;
    for (int i = 3; i <= a; i++)
    {
        while (a % i == 0)
        {
            // cout << "div " << i << endl;
            res = i;
            a /= i;
        }
    }
    return res;
}

int main()
{
    cin >> N >> P;
    int p = max_prime_div(P);
    int tmp = p;
    int res = 0;
    while (N >= tmp)
    {
        res += N / tmp;
        tmp *= p;
    }
    cout << res;
}