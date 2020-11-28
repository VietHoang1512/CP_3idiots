#include <bits/stdc++.h>
using namespace std;
long long max_ = 0;
long long N, m, k;
long long p[500];
long long Low, High, pmax;

bool Try(long long threshold)
{
    long long tmp = 0, non_allocated = k;
    for (long long i = m - 1; i >= 0; i--)
    {
        // cout << "________________________\n";
        // cout << "Non allocated book " << i + 1 << endl;
        // cout << "Non allocated person " << non_allocated << endl;
        // cout << "current book " << p[i] << endl;
        if ((tmp + p[i] <= threshold) && (i + 1 >= non_allocated))
        {
            tmp += p[i];
            // cout << "allocated " << p[i] << " to " << non_allocated << endl;
            if (i == 0)
                non_allocated--;
        }

        else
        {
            non_allocated--;
            tmp = p[i];
            // cout << "allocated " << p[i] << " to " << non_allocated << endl;
            if (i == 0)
                non_allocated--;
        }
    }
    if (non_allocated == 0)
        return true;
    return false;
}

void print_result(long long threshold)
{
    vector<long long> result;
    result.clear();
    long long tmp = 0, non_allocated = k;
    result.push_back(m - 1);
    for (long long i = m - 1; i >= 0; i--)
    {
        if ((tmp + p[i] <= threshold) && (i + 1 >= non_allocated))
        {
            tmp += p[i];
            if (i == 0)
                non_allocated--;
        }
        else
        {
            non_allocated--;
            tmp = p[i];
            if (i == 0)
                non_allocated--;
            result.push_back(i);
        }
    }
    long long index = result.size() - 1;
    tmp = result[index];
    for (long long i = 0; i < m; i++)
    {
        cout << p[i] << " ";
        if (i == tmp)
        {
            index--;
            tmp = result[index];
            if (i < m - 1)
                cout << " / ";
        }
    }
}

int main()
{
    cin >> N;
    while (N--)
    {
        cin >> m >> k;
        pmax = 0;
        for (long long i = 0; i < m; i++)
        {
            cin >> p[i];
            pmax = max(pmax, p[i]);
            // cout << p[i];
        }
        Low = pmax;
        High = 10e9;
        while (High > Low + 1)
        {
            long long mid = (High + Low) / 2;
            if (Try(mid))
            {
                High = mid;
            }
            else
            {
                Low = mid;
            }
        }
        // cout << "Got" << High << endl;
        print_result(High);
        cout << "\n";
    }
}