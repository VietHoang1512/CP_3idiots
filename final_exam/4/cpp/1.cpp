#include <bits/stdc++.h>

using namespace std;
const int mx = 100;
int n, Q;
int A[mx], D[mx][mx], visited[mx];
int dp[mx][mx];
int best_route[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("D:/VH/CP_3idiots/final_exam/4/cpp/input/input_3.txt", "r", stdin);
    // freopen("D:/VH/CP_3idiots/final_exam/4/cpp/submission/output_3.txt", "w", stdout);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> D[i][j];
        }
    }


    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]
        }
    }
    
}
