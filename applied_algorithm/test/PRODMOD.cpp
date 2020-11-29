#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;
long long N, ai, res = 1;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ai;
        res = (res * ai) % mod;
    }
    cout << res;
}