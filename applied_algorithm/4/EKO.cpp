#include <bits/stdc++.h>
using namespace std;

long long M, N, Hi, low = 0, mid, high;
vector<long long> H;

int received_wood(long long threshold)
{
    long long res = 0;
    for (auto h : H)
    {
        if (h > threshold)
            res += (h - threshold);
        if (res >= M)
            return 1;
    }
    return 0;
}
bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Hi);
        H.push_back(Hi);
        high = max(Hi, high);
    }
    int Hmax = high;
    // cout << high << low << endl;
    sort(H.begin(), H.end(), cmp);
    while (high > low + 1)
    {
        mid = (int)(low + high) / 2;
        // cout << mid << " recieved " << received_wood(mid) << endl;
        if (received_wood(mid))
        {
            low = mid;
            // mid = (int)(low + high) / 2;
        }
        else
        {
            high = mid;
            // mid = (int)(low + high) / 2;
        }
    }
    // if ((high-low==1)&&(!received_wood(high))){
    //     mid=low;
    // }
    cout << low;
}