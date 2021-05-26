#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string thousandSeparator(int n)
    {
        vector<char> v;
        int cnt = 0;
        if (n == 0)
            return "0";
        while (n)
        {
            v.push_back('0' + (n % 10));
            cnt++;
            n /= 10;
            if (!(cnt % 3))
            {
                if (n)
                    v.push_back('.');
            }
        }
        reverse(v.begin(), v.end());
        string res;
        for (auto c : v)
        {
            res += c;
        }
        return res;
    }
};