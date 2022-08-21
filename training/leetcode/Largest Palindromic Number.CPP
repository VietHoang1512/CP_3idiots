#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    string largestPalindromic(string num)
    {
        map<char, int> m;
        for (auto c : num)
        {
            m[c]++;
        }
        int res = 0, odd = 0, zero = 0;
        char non_zero = 'a', non_even = '0';
        for (auto c : "9876543210")
        {
            res += (m[c] / 2) * 2;
            if (m[c] % 2 )
            {
                if (!odd)
                {
                    non_even = c;
                    odd++;
                }
            }
        }
        // cout << "LEN " << res << endl;
        int l = m.size();
        if (m['0'] > 0 && l == 1)
        {
            return "0";
        }
        if (m['0'] == res)
        {
            if (odd)
            {
                string s = "";
                for (auto c : "97531")
                {
                    if (m[c])
                    {
                        s += c;
                        return s;
                    }
                }
            }
            return "0";
        }
        if (odd)
            res++;
        vector<char> v(res);
        int id = 0;
        for (auto p : "9876543210")
        {
            while (1)
            {
                if (m[p] >= 2)
                {
                    v[id] = p;
                    v[res - id - 1] = p;
                    id++;
                    m[p] -= 2;
                }
                else
                    break;
            }
        }
        v[id] = non_even;
        string s = "";
        for (auto c : v)
        {
            s += c;
        }
        return s;
    }
};