#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string replaceDigits(string s)
    {
        int total = s.size();
        for (int i = 1; i < total; i += 2)
        {
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};