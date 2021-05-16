#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int len1 = word1.size(), len2 = word2.size();
        int len = min(len1, len2);
        string res;
        for (int i = 0; i < len; i++)
        {
            res += word1[i];
            res += word2[i];
        }
        for (int i = len; i < max(len1, len2); i++)
        {
            if (len1 > len)
            {
                res += word1[i];
            }
            else if (len2 > len)
            {
                res += word2[i];
            }
        }
        return res;
    }
};