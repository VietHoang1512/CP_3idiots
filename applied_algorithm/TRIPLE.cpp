#include <bits/stdc++.h>
using namespace std;
long long N, K, ai;
vector<long long> a;

int main()
{
    long long res = 0;
    cin >> N >> K;
    for (long long i = 0; i < N; i++)
    {
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end());

    for (long long i = 0; i < N - 2; i++)
    {
        long long first_term = a[i];
        long long low = i + 1, high = N - 1;
        while (high > low)
        {
            long long s = first_term + a[low] + a[high];
            if (s > K)
            {
                high--;
            }
            else if (s < K)
            {
                low++;
            }
            else
            {
                res++;
                // high--;
                low++;
            }
        }
    }
    cout << res;
}