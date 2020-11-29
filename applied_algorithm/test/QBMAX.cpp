#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int M[102][102];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (j > 0)
            {

                if (i == 0)
                {
                    M[i][j] += max(M[i][j - 1], M[i + 1][j - 1]);
                }
                else if (i == m - 1)
                {
                    M[i][j] += max(M[i][j - 1], M[i - 1][j - 1]);
                }
                else
                {
                    M[i][j] += max(M[i][j - 1], max(M[i + 1][j - 1], M[i - 1][j - 1]));
                }
            }
        }
    }
    int mx = M[0][n - 1];
    for (int i = 0; i < m; i++)
    {
        mx = max(mx, M[i][n - 1]);
    }
    cout << mx;
}