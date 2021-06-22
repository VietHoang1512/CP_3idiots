#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> m;
        for (auto task : tasks)
        {
            m[task]++;
        }
        priority_queue<int> PQ;
        for (auto p : m)
        {
            PQ.push(p.second);
        }
        n++;
        int res = 0, total = PQ.size();
        while (total)
        {
            int cnt = min(total, n);
            vector<int> v;
            for (int i=0; i<cnt; i++)
            {
                int top = PQ.top() - 1;
                if (top)
                    v.push_back(top);
                PQ.pop();
            }
            for (auto top : v)
            {
                PQ.push(top);
            }
            total = PQ.size();
            if (total)
                res += n;
            else
                res += cnt;
        }
        return res;
    }
};