#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minOperations(int n)
    {
        if (n % 2)
            return (n * n - 1) / 4;
        return n * n / 4;
    }
};