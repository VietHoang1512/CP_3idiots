#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        // set<int> s;
        // for (auto x : arr)
        // {
        //     if (x % 2)
        //         s.insert(x);
        // }
        // if (s.size() < 3)
        //     return false;
        // vector<int> v;
        // v.insert(v.end(), s.begin(), s.end());
        // for (int i = 1; i < v.size() - 1; i++)
        // {
        //     if ((v[i] - v[i - 1] == 2) && (v[i + 1] - v[i] == 2))
        //     {
        //         return true;
        //     }
        // }
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if ((arr[i - 1] % 2) && (arr[i + 1] % 2) && (arr[i] % 2))
            {
                return true;
            }
        }
        return false;
    }
};