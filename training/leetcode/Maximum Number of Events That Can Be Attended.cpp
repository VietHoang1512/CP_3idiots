#include <bits/stdc++.h>
using namespace std;

int main()
{
}

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), cmp);
        int cur = -1, res = 0;
        cout << endl;
        for (auto e : events)
        {
            
            if (e[1] < cur+1)
            {
                continue;
            }
            cur++;
            cur = max(cur, e[0]);

            cout << "Day " << cur << " " << e[0] << "-" << e[1] << endl;
            res++;
            
        }
        return res;
    }
};