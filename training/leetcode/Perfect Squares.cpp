#include <bits/stdc++.h>
using namespace std;

int main()
{
}


class Solution
{
public:
    int dp[10005];
    int numSquares(int n)
    {   
        
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {   
            dp[i] = i;

            
            if (isSquare(i))
            {
                dp[i] = 1;
                continue;
            }
            

            for (int j = 1; j <= sqrt(i); j++)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
            

            cout << dp[i] << " ";
        }
        return dp[n];
        // int res = 0;
        // while(n){
        //     n -= maxSquareLessThan(n);
        //     res++;
        // }
        // return res;
    }
    bool isSquare(int n){
        return maxSquareLessThan(n)==n;
    }
    int maxSquareLessThan(int n)
    {
        int res = sqrt(n * 1.0);

        return res * res;
    }
};