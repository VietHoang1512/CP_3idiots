#include <bits/stdc++.h>
using namespace std;
int N, K, ai;
vector<int> a;
int cnt[10000];
int low, high;
int main()
{
    int res = 0;
    cin >> N >> K;
    if (N < 3)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < N; i++)
    // {
    //     cout << a[i] << " ";
    // }

    for (int i = 0; i < N - 2; i++)
    {
        //     for (int j = i + 1; j < N - 1; j++)
        //     {
        //         int low = j + 1, high = N - 1;
        //         while (high > low)
        //         {
        //             int mid = (high + low) / 2;
        //             int s = a[i] + a[j] + a[mid];
        //             if (s > K)
        //                 high = mid;
        //             if (s < K)
        //                 low = mid;
        //             if (s==K){
        //                 res++
        //             }

        //         }
        //     }
        int first_term = a[i];

        set<int> s;
        memset(cnt, 0, sizeof(cnt));
        for (int k = i + 1; k < N; k++)
        {
            s.insert(a[k]);
            cnt[a[k]]++;
        }
        vector <int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        sort(v.begin(), v.end());

        low = 0, high = v.size();
        // for (auto x:v){
        //     cout << x << " ";
        // }
        while (high > low)
        {
            int sum = first_term + v[low] + v[high];
            if (sum > K)
            {
                high--;
            }
            else if (sum < K)
            {
                low++;
            }
            else
            {
                res += cnt[v[low]] * cnt[v[high]];
                // cout << "haha\n" << endl;
                high--;
                // low++;
            }
        }
    }
    cout << res;
}