#include <bits/stdc++.h>
using namespace std;

const int mx = 2e6;

int n, b, tmp;
int A[mx], pLeft[mx], pRight[mx];
int x, y;
int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    tmp = A[0];
    for (int i = 0; i < n; i++)
    {
        tmp = max(tmp, A[i]);
        pLeft[i] = tmp;
        // cout << tmp << " ";
    }
    cout << endl;
    tmp = A[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        tmp = max(tmp, A[i]);
        pRight[i] = tmp;
        // cout << tmp << " ";
    }
    tmp = -1;
    for (int i = 1; i < n - 1; i++)
    {
        x = pLeft[i - 1] - A[i];
        y = pRight[i + 1] - A[i];
        // cout << i << " " << A[i] << " " << x << " " << y << endl;
        if ((x>=b)&&(y>=b)) tmp = max(tmp, x+y);
    }
    cout << tmp;
    return 0;
}
