#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define __builtin_popcount __builtin_popcountll
// #define SCD(t) scanf("%d", &t)
// #define SCLD(t) scanf("%ld", &t)
// #define SCLLD(t) scanf("%lld", &t)
// #define SCC(t) scanf("%c", &t)
// #define SCS(t) scanf("%s", t)
// #define SCF(t) scanf("%f", &t)
// #define SCLF(t) scanf("%lf", &t)
// #define read(type) readInt<type>()
// #define IN(A, B, C) assert(B <= A && A <= C)

int main()
{
}

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        map<int, int> mp;
        for (auto row : matrix)
        {
            for (auto e : row)
            {
                mp[e]++;
            }
        }
        int c;
        for (int i = 1; i < INT_MAX / 2; i++)
        {
            if (!mp.count(i))
            {
                c = i;
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][j] = c;
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[k][j])
                            matrix[k][j] = c;
                    }
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[i][k])
                            matrix[i][k] = c;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == c)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};