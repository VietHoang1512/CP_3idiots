#include <bits/stdc++.h>
using namespace std;

const int mx = 30;
const int mod = 1e9 + 7;

int n, K, Q, res = 0, used = 0;
int d[mx], allocated[mx];
int trucks[mx];

int factorial(int x)
{
    int tmp = 1;
    for (int i = 1; i <= x; i++)
    {
        tmp *= i;
    }
    return tmp % mod;
}

void Try(int k)
{

    if (k == n + 1)
    {
        if (used < K)
            return;
        // int tmp = 1;
        // for (int j = 1; j <= K; j++)
        // {
        //     int size = trucks[j].size();
        //     if (size)
        //         tmp = (tmp * size) % mod;
        // }
        int tmp = 1;
        for (int j = 1; j <= K; j++)
        {
            // cout << "Truck " << j << endl;
            int size = trucks[j];
            if (size)
                tmp = (tmp * factorial(size)) % mod;
            // for (int i : trucks[j])
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
        }
        res = (res + tmp) % mod;
        // res = (res + 1) % mod;
        // cout << "DONE\n";
        return;
    }

    for (int j = 1; j <= min(used + 1, K); j++)
    {
        if (j == used + 1)
        {
            allocated[j] += d[k];
            trucks[j]++;
            used++;
            Try(k + 1);
            trucks[j]--;
            used--;
            allocated[j] -= d[k];
        }
        else if ((allocated[j] + d[k]) <= Q)
        {
            allocated[j] += d[k];
            trucks[j]++;
            Try(k + 1);
            trucks[j]--;
            allocated[j] -= d[k];
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    Try(1);
    cout << res;

    // int k_fact = factorial(K);

    // for (int i = 0; i < mod; i++)
    // {
    //     if (!((k_fact * i - res) % mod))
    //     {
    //         cout << i;
    //         return 0;
    //     }
    // }
    // cout << res;
}