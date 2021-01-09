#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int res;
int pos[1000];
int n, h;
// bool UCV(int j, int k)
// {
//     if (j == 1)
//     {
//         if (countNb1 >= k2)
//             return false;
//     }
//     else
//     {
//         if (k == 1)
//             return true;
//         else
//         {
//             if (countNb1 < k1 || pos[k - 1] == 0)
//                 return false;
//         }
//     }
//     return true;
// }

void ghinhan()
{
    for (int i = 1; i <= n; i++)
    {
        cout << pos[i];
    }
    cout << endl;
}

void Try(int k)
{
    int j;
    for (int j = 0; j <= 1; j++)
    {
        int tmp = res;
        if (j == 1)
        {
            res++;
        }
        pos[k] = j;
        if (k == n)
        {
            if (res == h)
                ghinhan();
        }
        else
        {
            Try(k + 1);
        }
        res = tmp;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> h;
        res = 0;
        Try(1);
        cout << endl;
    }
}