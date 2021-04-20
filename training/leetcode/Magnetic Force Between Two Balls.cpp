#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {   
        sort(position.begin(), position.end());
        int total = position.size();
        int l = 1, r = position[total-1];
        while (r > l+1)
        {   
            int tmp = (r + l) / 2;
            // cout << l << " " << r << " " << tmp << endl;

            // cout << "Trying to allocate with size " << tmp << endl;
            if (allocatable(position, m, tmp))
            {
                l = tmp;
                // cout << "Successful\n";
            }
            else
            {   
                // cout << "Fail\n";
                r = tmp;
            }
        }
        return l;
    }
    bool allocatable(vector<int> &position, int m, int k)
    {
        int total = position.size();
        m--;
        int cur = position[0];
        // cout << "cur " << cur << endl;
        for (int i = 1; i < total; i++)
        {
            if ((position[i] - cur) >= k)
            {
                m--;
                cur = position[i];
                // cout << "cur " << cur << endl;

            }
        }
        if (m > 0)
            return false;
        return true;
    }
};