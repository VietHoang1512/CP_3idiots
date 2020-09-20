#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, SumTime, MaxSumTime = 0;
    int Time[30], MinTime[30], MaxTime[30];
    cin >> d >> SumTime;
    for (int i = 0; i < d; i++)
    {
        Time[i] = 0;
        cin >> MinTime[i] >> MaxTime[i];
        SumTime -= MinTime[i];
        MaxTime[i] -= MinTime[i];
        MaxSumTime += MaxTime[i];
        //cout << MaxTime[i];
    }

    if ((SumTime < 0) || (SumTime > MaxSumTime))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        int i = 0;
        while (SumTime)
        {
            if (MaxTime[i])
            {
                Time[i]++;
                MaxTime[i]--;
                SumTime--;
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < d; i++)
        {
            cout << Time[i] + MinTime[i] << " ";
        }
    }
}
