#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        cout << "\n\n";
        int total = nums.size();
        vector<int> v(1, 0);
        for (int i = 0; i < total - 1; i++)
        {
            if (nums[i + 1] - nums[i] - 1)
                v.push_back(i + 1);
        }
        for (auto x : v)
        {
            cout << x << " ";
        }

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - v[i - 1] < 3)
                return false;
        }
        return true;
    }
};