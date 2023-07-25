#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i < n-1; i++)
        {
            vector<int> v;
            int m = n;
            while (m)
            {
                v.push_back(m % i);
                m /= i;
            }
            int len = v.size();
            for (int j = 0; j < len / 2; j++)
            {
                if (v[j] != v[len - j - 1])
                    return false;
            }
            
        }
        return true;
    }
};