#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num==0) return 0;
        for (int i = 1; i <= 10; i++)
        {
            if ((num - k * i) < 0)
                return -1;
            if ((num - k * i) % 10 == 0)
            {
                return i;
            }
        }
        return -1;
    }
};