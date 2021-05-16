#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int tmp = (high - low + 1) / 2;
        if ((high % 2) && (low % 2))
            tmp++;
        return tmp;
    }
};