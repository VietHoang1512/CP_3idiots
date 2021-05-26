#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        vector<int> v;
        while (n)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        return accumulate(v.begin(), v.end(), 1, multiplies<int>()) - accumulate(v.begin(), v.end(), 0);
    }
};