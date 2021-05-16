#include <bits/stdc++.h>
using namespace std;

int main()
{

}


class Solution
{
public:
    int minPartitions(string n)
    {
        int tmp = 0;
        int len = n.size();
        for (int i = 0; i <= len; i++)
        {
            tmp = max(tmp, n[i] - '0');
        }
        return tmp;
    }
};