#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int countNb1;
int pos[1000];
int n, k1, k2;
bool UCV(int j, int k)
{
    if (j)
    {
        if (countNb1 >= k2)
            return false;
    }
    else
    {
        if (k == 1)
            return true;
        else
        {
            if (countNb1 < k1 || pos[k - 1] == 0)
                return false;
        }
    }
    return true;
}

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
        if (UCV(j, k))
        {
            pos[k] = j;
            int tmp = countNb1;
            if (j == 1)
                countNb1++;
            else
                countNb1 = 0;
            if (k == n)
            {
                if (countNb1 >= k1 || countNb1 == 0)
                    ghinhan();
            }
            else
            {
                Try(k + 1);
            }
            countNb1 = tmp;
        }
    }
}
int main()
{

    cin >> n >> k1 >> k2;
    Try(1);
}