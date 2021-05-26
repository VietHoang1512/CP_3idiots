#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string generateTheString(int n)
    {
        if (n % 2)
        {
            string tmp(n, 'a');
            return tmp;
        }
        string tmp(n - 1, 'a');
        return tmp + 'b';
    }
};