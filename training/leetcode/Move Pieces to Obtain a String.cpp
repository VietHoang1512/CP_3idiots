#include <bits/stdc++.h>
using namespace std;

int main()
{
}


class Solution
{
public:
    bool canChange(string s1, string s2)
    {
        s1.insert(0, "LR");
        s2.insert(0, "LR");
        vector<char> s, t;
        for (auto c : s1)
        {
            if (c != '_')
            {
                s.push_back(c);
            }
        }
        for (auto c : s2)
        {
            if (c != '_')
            {
                t.push_back(c);
            }
        }
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2)
        {
            return false;
        }
        for (int i = 0; i < len1; i++)
        {
            if (s[i] != t[i])
            {
                return false;
            }
        }
        vector<int> l1, r1;
        int len = s1.size();
        for (int i = 0; i < len; i++)
        {
            if (s1[i] == 'L')
                l1.push_back(i);
            else if (s1[i] == 'R')
                r1.push_back(i);
        }
        int idl = 0, idr = 0;
        int posl = l1[idl], posr = r1[idr];
        l1.push_back(INT_MAX);
        r1.push_back(INT_MAX);
        for (int i = 0; i < len; i++)
        {
            if (s2[i] == 'L')
            {
                if (i > posl)
                    return false;
                if (posr < posl && i<posr)
                    return false;
                posl = l1[++idl];
            }
            else if (s2[i] == 'R')
            {
                if (i < posr)
                    return false;
                if (posl < posr && i<posl)
                    return false;
                posr = r1[++idr];
            }
        }
        return true;
    }
};