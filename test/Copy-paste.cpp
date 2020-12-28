#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int mx = 100;
int main()
{
    const int mx = 10000;
    int test, n, k;
    int A[mx];
    cin >> test;
    // cout << "Num test case " << test << endl;

    for (int t = 0; t < test; t++)
    {
        // cout << "On test " << t << "\n";
        cin >> n >> k;
        // memset(A, 0, sizeof(A));

        for (int i = 0; i < n; i++)
            cin >> A[i];

        int cnt = 0;
        int new_min, cur_min;
        bool is_new;
        int src = -1;
        cur_min = A[0] + 1;

        for (int x = 0; x < n * k; x++)
        {
            // cout << "Finding min\n";
            is_new = false;
            for (int i = 0; i < n; i++)
            {
                if ((A[i] < cur_min) && (i != src))
                {
                    cur_min = A[i];
                    is_new = true;
                    src = i;
                    // cout << "new min " << A[i] << endl;
                }
            }

            if (!is_new)
            {
                // cout << "result ";
                cout << cnt << endl;
                break;
            }

            for (int i = 0; i < n; i++)
            {
                {
                    if (i != src)
                    {
                        while (A[i] <= k - cur_min)
                        {
                            cnt++;
                            // cout << "Increasing " << i << " from " << A[i] << " to " << (A[i] + cur_min) << endl;
                            A[i] += cur_min;
                        }
                    }
                }
            }
        }
    }
}