#include <bits/stdc++.h>

using namespace std;
float n, l, ai;

set<float> s;
int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        // a.push_back(ai);
        s.insert(ai);
    }
    vector<float> a(s.size());
    copy(s.begin(), s.end(), a.begin());
    sort(a.begin(), a.end());
    float left = a[0], right = l - a[a.size() - 1];
    float max_dis = 0;
    for (int i = 0; i < a.size() - 2; i++)
    {
        max_dis = max(max_dis, a[i + 1] - a[i]);
    }
    float res = max(left, right);
    res = max(res, max_dis / 2);
    cout << fixed << setprecision(10) << res;
}