#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        map<char, char> m;
        int i = 0;
        char t = 'a';
        for (auto c : key)
        {
            if (c != ' ')
            {
                m.insert({c, ((char)(t++))});
                cout << c << " " << ((char)(t - 1)) << endl;
            }
        }
        m[' '] = ' ';
        string s = "";
        for (auto c : message)
        {
            s += m[c];
        }
        cout << "\n";
        return s;
    }
};