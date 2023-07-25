#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxHappyGroups(int batchSize, vector<int> &groups)
    {
        int res = 0, total = groups.size();
        map<int, int> m;
        for (auto g : groups)
        {
            m[g % batchSize]++;
        }
        // group 1
        res += m[0];
        // m[0] = 0;

        cout << "\nGroup 1: " << res;
        // group 2
        for (int i = 1; i < batchSize; i++)
        {
            if (batchSize != (2 * i))
            {
                int tmp = min(m[i], m[batchSize - i]);
                m[i] -= tmp;
                m[batchSize - i] -= tmp;
            }
            else
            {
                int tmp = m[i] / 2;
                m[i] -= tmp * 2;
            }

            res += tmp;
            // cout << "\n"
            //      << i << (batchSize - i) << tmp;
        }
        cout << "\nGroup 1+2: " << res;

        map<int, int> id2remainder, remainder2id;
        // group 3
        int id = 1;
        for (int i = 1; i < batchSize; i++)
        {
            if (m[i])
            {
                id2remainder[id] = i;
                remainder2id[i] = id;
            }
            id++;
        }

        int len = id2remainder.size();
        // cout << "len " << len << endl;
        for (int i = 1; i < (1 << len); i++)
        {
            // cout << i;
            if (__builtin_popcount(i) == 3)
            {
                int mn = INT_MAX;
                for (auto p : id2remainder)
                {
                    if (i && (1 << p.first))
                        mn = min(mn, m[p.second]);
                }
                for (auto p : id2remainder)
                {
                    if (i && (1 << p.first))
                        m[p.second] -= mn;
                }
                res += mn;
            }
        }
        cout << "\nGroup 1+2+3: " << res;

        for (int i = 1; i < (1 << len); i++)
        {
            // cout << i;
            if (__builtin_popcount(i) == 4)
            {
                int mn = INT_MAX;
                for (auto p : id2remainder)
                {
                    if (i && (1 << p.first))
                        mn = min(mn, m[p.second]);
                }
                for (auto p : id2remainder)
                {
                    if (i && (1 << p.first))
                        m[p.second] -= mn;
                }
                res += mn;
            }
        }
        int tmp = 0;
        for (auto p : m)
        {
            tmp = max(tmp, p.second);
        }
        if (!tmp)
            if (m[0] < 2)
                res--;
        cout << "\nGroup 1+2+3+4: " << res;

        return res;
    }
};