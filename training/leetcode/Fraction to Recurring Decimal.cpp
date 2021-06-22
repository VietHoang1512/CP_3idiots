#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        float res = (numerator + .0) / denominator;
        return to_string(res);
    }
};