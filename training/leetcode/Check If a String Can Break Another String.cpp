#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        vector<int> v1, v2;
        v1.insert(v1.end(), s1.begin(), s1.end());
        v2.insert(v2.end(), s2.begin(), s2.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int l = 0, r = 0, total = v1.size();
        for (int i = 0; i < total; i++)
        {
            if (v1[i] >= v2[i])
            {
                l++;
            }
            if (v1[i] <= v2[i])
            {
                r++;
            }
        }
        // for (auto x : v1)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        cout << l << " " << r << " " << total << endl;
        if (!((l - total) * (r - total)))
            return true;
        return false;
    }
};