#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6;

int n_test, N, C;
int xi;
vector<int> x;
bool satisfied(int k)
{
    // cout << "Try " << k << endl;
    int cur = x[1];
    int allocated = 1;
    for (int i = 2; i <= N; i++)
    {
        if (x[i] - cur >= k)
        {
            allocated++;
            cur = x[i];
            if (allocated >= C)
            {
                // cout << "OK\n";
                return true;
            }
        }
    }
    // cout << "Not OK\n";
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n_test;
    while (n_test--)
    {
        x.clear();
        x.push_back(0);
        cin >> N >> C;
        for (int i = 1; i <= N; i++)
        {
            cin >> xi;
            // cout << x[i] << " ";
            x.push_back(xi);
        }
        sort(x.begin(), x.end());
        // for (int i = 1; i <= N; i++)
        // {
        //     cout << x[i] << " ";
        // }
        // cout << endl;

        int low = 1, high = x[N] / C + 1;
        int mid;
        while (high > low + 1)
        {
            mid = (low + high) / 2;
            if (satisfied(mid))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << low << endl;
    }
}