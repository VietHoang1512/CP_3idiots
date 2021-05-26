#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        vector<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // unordered_map<char, int> m;
        // for (auto c : vowel)
        // {
        //     m[c] = 0;
        // }
        int total = s.size(), diff = 0;
        for (int i = 0; i < total; i++)
        {
            if (find(vowel.begin(), vowel.end(), s[i]) != vowel.end())
                diff += (i < (total / 2)) ? 1 : -1;
        }
        return diff == 0;
        // for (auto c : vowel)
        // {
        //     if (m[c])
        //     {

        //         cout << c << " " << m[c] << endl;
        //         return false;
        //     }
        // }
        // cout << endl;
        // return true;
    }
};