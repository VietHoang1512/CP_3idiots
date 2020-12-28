#include <bits/stdc++.h>

using namespace std;
const int mx = 1e5;
int A[mx];

int N, M, res = 0;

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        res += (A[i] <= M);
    }
    for (int i = 1; i < N; i++)
    {
        int sum = A[i];
        for (int j = i + 1; j <= N; j++)
        {
            sum += A[j];
            res += (sum <= M);
        }
    }
    cout << res;
}