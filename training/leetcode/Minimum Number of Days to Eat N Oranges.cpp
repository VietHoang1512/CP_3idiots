#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    unordered_map <int, int> m;
    int minDays(int n)
    {
        if (n == 1)
            return m[1] = 1;

        vector<int> v;
        if (n % 3 == 0)
        {
            if (m.count(n / 3))
            {
                v.push_back(m[n / 3]);
            }
            else
                v.push_back(minDays(n / 3));
        }
        else if (n % 2 == 0)
        {
            if (m.count(n / 2))
            {
                v.push_back(m[n / 2]);
            }
            else
                v.push_back(minDays(n / 2));
        }
        if (m.count(n - 1))
        {
            v.push_back(m[n - 1]);
        }
        else
            v.push_back(minDays(n - 1));
        m[n] = 1 + *min_element(v.begin(), v.end());
        return m[n];
    }
};