#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}
class Solution
{
public:
    map<int, int> m;
    bool isHappy(int n)
    {
        if (n == 1)
            return 1;
        if (m.count(n))
            return 0;
        int tmp = 0;
        while (n)
        {
            tmp += pow(n % 10, 2);
            n /= 10;
        }
        m[tmp] = 1;
        return isHappy(tmp);
    }
};