#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        value = abs(value);
        int total = nums.size();
        map<int, int> m;
        for (int i = 0; i < total; i++)
        {
            nums[i] = (nums[i] % value + value) % value;
            m[nums[i]]++;
            // cout << nums[i] << " ";
        }
        int mn = m[0];
        for (int i = 0; i < value; i++)
        {
            mn = min(mn, m[i]);
        }
        
        for (int i = 0; i < value; i++)
        {
            if(m[i]==mn){
                return mn*value+i;
            }
        }
        return 0;
    }
};