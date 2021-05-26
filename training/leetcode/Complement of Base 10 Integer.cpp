#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int res = 1, tmp = 0;
        cout << endl;
        while (++tmp)
        {
            // cout << (n >> tmp) << endl;
            if (!(n >> tmp))
            {
                break;
            }
        }
        return (n ^ ((1 << tmp) - 1));
    }
};