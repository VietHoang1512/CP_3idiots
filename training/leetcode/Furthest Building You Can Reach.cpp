#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int total = heights.size();
        // for (int i = 0; i < total; i++)
        // {
        //     cout << Allocated(heights, i, bricks, ladders) << " ";
        // }
        // cout << endl;
        int l = 0, r = total - 1;
        while (r > l)
        {
            int tmp = (r + l) / 2;
            // cout << l << "-" << r << "-" << tmp<< ",";

            if (Allocated(heights, tmp, bricks, ladders))
            {
                l = tmp;
            }
            else
            {
                r = tmp;
            }
            if ((r - l) == 1)
                if (Allocated(heights, r, bricks, ladders))
                    return r;
                else
                    return l;
        }
        cout << endl;

        return l;
    }
    bool Allocated(vector<int> h, int n, int bricks, int ladders)
    {
        vector<int> heights = h;
        if (n == 0)
            return true;
        priority_queue<int> pq;
        // pq.clear();
        for (int i = 1; i <= n; i++)
        {
            if (heights[i] > heights[i - 1])
                pq.push(heights[i] - heights[i - 1]);
        }
        while (pq.size() && ladders)
        {
            pq.pop();
            ladders--;
        }
        if (!pq.size())
            return true;
        while (pq.size())
        {
            int top = pq.top();
            bricks -= top;
            pq.pop();
        }
        return bricks >= 0;
    }
};