#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {
        map<char, int> m;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (m.count(s[i]))
            {
                m[s[i]] = abs(i - m[s[i]]) - 1;
            }
            else
                m[s[i]] = i;
        }
        for (auto i : m)
        {
            if (abs(i.second) != distance[i.first - 'a'])
                return false;
        }
        return true;
    }
};