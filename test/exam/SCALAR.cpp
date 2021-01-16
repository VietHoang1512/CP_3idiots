#include <bits/stdc++.h>

using namespace std;

long long T, n, x, y;
vector<long long> A, B;

int main()
{
    cin >> T;
    for (long long t = 1; t <= T; t++)
    {
        A.clear();
        B.clear();
        cin >> n;
        for (long long i = 1; i <= n; i++)
        {
            cin >> x;
            A.push_back(x);
        }
        for (long long i = 1; i <= n; i++)
        {
            cin >> x;
            B.push_back(x);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long res = 0;
        for (long long i = 0; i < n; i++)
        {
            res += A[i] * B[n-1-i];
        }
        cout << "Case #" << t << ": " << res << endl;
    }
}