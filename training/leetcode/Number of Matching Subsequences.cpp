#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 'z' - 'a' + 1;
class Solution
{

public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int res = 0;
        // for (auto word : words)
        //     res += Check(s, word);
        // return res;

        int total = s.size();
        vector<vector<int>> v(mx);
        for (int i = 0; i < total; i++)
            v[s[i] - 'a'].push_back(i);
        for (auto word : words)
        {
            int len = word.size();
            int cur = -1;
            int score = 1;
            for (auto c : word)
            {
                auto it = upper_bound(v[c - 'a'].begin(), v[c - 'a'].end(), cur);
                if (it == v[c - 'a'].end())
                    score = 0;
                else
                    cur = *it;
            }
            res += score;
        }
        return res;
    }
    // bool Check(string a, string b)
    // {
    //     int lena = a.size(), lenb = b.size(), l = 0, r = 0;

    //     while ((l < lena) && (r < lenb))
    //     {
    //         if (a[l] == b[r])
    //         {
    //             r++;
    //         }
    //         l++;
    //     }

    //     if (r == lenb)
    //         return true;
    //     return false;
    // }
};