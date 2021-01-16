// #include <bits/stdc++.h>

// using namespace std;
// const int mx = 2e5;
// int T, a[mx], n;
// int dp[mx];

// int lis(int i)
// {
//     if (dp[i] > 0)
//     {
//         return dp[i];
//     }
//     int x = 1;
//     for (int j = 0; j < i; j++)
//     {
//         if ((a[j] + 1) == a[i])
//         {
//             x = max(x, lis(j) + 1);
//         }
//     }
//     dp[i] = x;
//     return x;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> T;
//     for (int t = 1; t <= T; t++)
//     {
//         int res = 1, pos = 0;
//         memset(dp, -1, sizeof(dp));
//         memset(a, 0, sizeof(a));

//         cin >> n;
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         for (int i = 1; i < n; i++)
//         {
//             if (res < lis(i))
//             {
//                 res = lis(i);
//                 // pos = i;
//             }
//         }
//         cout << res << endl;
//     }
// }