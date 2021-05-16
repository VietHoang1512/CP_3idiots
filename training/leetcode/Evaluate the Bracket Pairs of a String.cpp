#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        map<string, string> m;
        for (auto x : knowledge)
        {
            m[x[0]] = x[1];
        }
        int total = s.size();
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
                v.push_back(i);
        }
        int tmp = 0;
        for (int i = 0; i < v.size(); i += 2)
        {
            cout << tmp + v[i] << " " << tmp + v[i + 1] << endl;
            string key = s.substr(tmp + v[i] + 1, v[i + 1] - v[i] - 1);
            cout << "KEY:" << key << endl;
            if (m.count(key))
            {
                s.replace(tmp + v[i], v[i + 1] - v[i] + 1, m[key]);
                tmp += (m[key].size() - key.size() - 2);
            }
            else
            {
                s.replace(tmp + v[i], v[i + 1] - v[i] + 1, "?");
                tmp += (1 - key.size() - 2);
            }
            cout << s << endl;
        }
        return s;
    }
};