#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool splitString(string s)
    {
        int total = s.size();
        for (int i = pow(2, total - 1); i < pow(2, total); i++)
        {
            if (CHECK(s, i))
                return true;
        }
        // cout << CHECK(s, 41);
        return false;
    }
    bool CHECK(string s, int hash)
    {
        int total = s.size();

        vector<int> v;
        for (int i = total - 1; i >= 0; i--)
        {
            if ((hash >> i) & 1)
            {
                v.push_back(total - i - 1);
            }
        }
        v.push_back(total);
        // cout << "\n V: ";
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        if (v.size() < 3)
            return false;
        vector<int> res;
        for (int i = 0; i < v.size() - 1; i++)
        {
            string tmp = "";
            for (int j = v[i]; j < v[i + 1]; j++)
            {
                tmp = tmp + s[j];
            }
            if (v[i + 1] - v[i] >= 10)
                return false;
            // cout << tmp << " ";
            res.push_back(stoi(tmp));
        }
        // cout << "\n RES: ";
        // for (auto x : res)
        // {
        //     cout << x << " ";
        // }
        for (int i = 0; i < v.size() - 2; i++)
        {
            if (res[i] - res[i + 1] - 1)
                return false;
        }
        return true;
    }
};