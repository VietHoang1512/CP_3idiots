#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() > sentence2.size())
        {
            string tmp = sentence1;
            sentence1 = sentence2;
            sentence2 = tmp;
        }

        int len1 = sentence1.size(), len2 = sentence2.size();

        for (int i = 0; i < len1; i++)
        {
            if (sentence1[i] == ' ')
            {
            }
        }
    }
    bool CHECK(string s, string left, string right)
    {
        int len = s.size(), len_l = left.size(), len_r = right.size(),
        
    }
};