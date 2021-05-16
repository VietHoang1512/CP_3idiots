#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        int res = 0;
        set<string> s;
        word += 'a';
        int total = word.size();
        string tmp = "";
        for (int i = 0; i < total; i++)
        {
            if ((word[i] < '0') || (word[i] > '9'))
            {
                if (tmp.size())
                {
                    tmp.erase(0, tmp.find_first_not_of('0'));
                    s.insert(tmp);
                    tmp = "";
                }
            }
            else
            {
                tmp += word[i];
            }
        }

        return s.size();
    }
};