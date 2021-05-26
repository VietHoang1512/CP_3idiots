#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        vector<string> v;
        int cnt0 = 0, cnt1 = 0;
        string tmp;
        for (auto c : s)
        {
            if (c == '(')
                cnt0++;
            else
                cnt1++;
            tmp += c;
            if (cnt0 == cnt1)
            {
                v.push_back(tmp);
                tmp = "";
                cnt0 = cnt1 = 0;
            }
        }

        string res;
        cout << endl;
        for (auto s : v)
        {
            cout << s << "  ";
            res += (s.substr(1, s.size() - 2));
        }
        return res;
    }
};