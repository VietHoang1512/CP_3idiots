#include <bits/stdc++.h>
using namespace std;

int main()
{
}

void showPQ(priority_queue<pair<int, int>> pq)
{
    priority_queue<pair<int, int>> tmp = pq;
    while (tmp.size())
    {
        cout << tmp.top().first << "-" << tmp.top().second << ",";
        tmp.pop();
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int total = barcodes.size();
        if (total == 1)
            return barcodes;
        map<int, int> cnt;
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        // sort(barcodes.begin(), barcodes.end());
        for (auto x : barcodes)
        {
            if (cnt.count(x))
                cnt[x]++;
            else
                cnt[x] = 1;
        }
        for (auto x : cnt)
        {
            pq.push({x.second, x.first});
        }
        // showPQ(pq);

        while (pq.size())
        {
            int cx = pq.top().first, x = pq.top().second;
            pq.pop();
            int cy = pq.top().first, y = pq.top().second;
            pq.pop();
            if (cx > 1)
                pq.push({cx - 1, x});
            if (cy > 1)
                pq.push({cy - 1, y});

            res.push_back(x);
            res.push_back(y);
            if ((int)pq.size() == 1)
            {
                res.push_back(pq.top().second);
                break;
            }
        }
        return res;
    }
};
