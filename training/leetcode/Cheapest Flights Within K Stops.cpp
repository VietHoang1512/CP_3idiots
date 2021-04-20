#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mx = 105;
class Solution
{
public:
    // int dp[mx][mx];
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
        vector<vector<int>> weight(n, vector<int>(n, 0));

        for (auto x : flights)
        {
            weight[x[0]][x[1]] = x[2];
            weight[x[1]][x[0]] = x[2];
        }
        for(int i=1; i<=k; i++){
            
        }
        return 0;
    }
};