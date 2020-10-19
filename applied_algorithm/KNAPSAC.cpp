#include <bits/stdc++.h>
using namespace std;
const int mx = 30;
int n, b, amin = INT_MAX, res = 0;
// int ai, ci;
// vector<pair<int, int>> v;

int A[mx], C[mx], items[mx];
int cur_c = 0, cur_a = 0;

// void Try(int j)
// {
//     // cout << endl;
//     if (cur_a + amin > b || j == n - 1)
//     {
//         res = max(res, cur_c);
//         return;
//     }

//     for (int i = j + 1; i < n; i++)
//     {
//         if (!items[i])
//         {
//             items[i] = 1;
//             cur_a += A[i];
//             cur_c += C[i];
//             // cout << "Got" << i << " cost: " << cur_c << " weight " << cur_a << endl;
//             if (cur_a <= b)
//                 Try(i);
//             items[i] = 0;
//             cur_a -= A[i];
//             cur_c -= C[i];
//             // cout << "Back\n";
//         }
//     }
// }

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> C[i];
        // v.push_back(pair<int, int>(ai, ci));
        amin = min(amin, A[i]);
    }
    for (int i = 0; i < pow(2, n); i++)
    {
        cur_a = 0, cur_c = 0;
        // cout << "Checking " << i << endl;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                cur_a += A[j];
                cur_c += C[j];
            }
        }

        if (cur_a <= b)
            res = max(res, cur_c);
    }
    // Try(0);
    cout << res;
    // cout << "\nDONE";
}
// int  m[mx], v[mx], M;

// int main()
// {
//     cin >> n >> M;
//     for (int i = 0; i < n; ++i)
//         cin >> m[i] >> v[i];
//     int ans = 0;
//     for (int mask = 1 << n; mask--;)
//     {
//         // for (int i = 0; i < n; i++)
//         cout << mask<< " ";
//         cout << endl;
//         // int sumM = 0, sumV = 0;
//         // for (int i = 0; i < n; ++i)
//         //     if (mask >> i & 1)
//         //     { // bit thu i = 1
//         //         sumM += m[i];
//         //         sumV += v[i];
//         //     }
//         // if (sumM <= M)
//         //     ans = max(ans, sumV);
//     }
//     cout << ans;
// }