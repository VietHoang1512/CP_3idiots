#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    unsigned long long distinctNames(vector<string> &ideas)
    {
        unsigned long long base = 1000;
        map<unsigned long long, unsigned long long> ban;
        vector<int> v;
        for (auto idea : ideas)
        {
            unsigned long long tmp = num(idea, base);
            ban.insert({tmp, 1});
            v.push_back(tmp);
        }
        unsigned long long n = ideas.size(), res = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cout << ideas[i] << " " << v[i] << " "<< ideas[j] << " "<<v[j];

                unsigned long long s1 = v[i], s2 = v[j];
                unsigned long long d1 = s1 % base, d2 = s2 % base;
                s1 = s1 - d1 + d2;
                s2 = s2 - d2 + d1;
                if (ban.find(s1) == ban.end() && ban.find(s2) == ban.end())
                {
                    res += 2;
                    cout << " yes \n";
                }else cout << "no \n";
            }
        }
        cout << "***\n";
        return res;
    }
    unsigned long long num(string s, unsigned long long base)
    {
        unsigned long long res = 0, p = 1;
        for (auto s_ : s)
        {
            res += (s_ - 'a') * p;
            p = p*base;
        }
        return res;
    }
};