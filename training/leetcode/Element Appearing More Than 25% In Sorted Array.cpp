#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        arr.push_back(-1);
        int total = arr.size();
        int prev, cur = -1;
        // cout << endl;
        for (int i = 0; i < total; i++)
        {
            if (arr[i] != arr[i + 1])
            {
                prev = cur;
                cur = i;
                // cout << cur << " " << prev << endl;
                if ((cur - prev) > ((total - 1) / 4))
                    return arr[i];
            }
        }
        return 0;
    }
};