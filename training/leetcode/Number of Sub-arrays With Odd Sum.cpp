#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mod = 1e9 + 7;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int total = arr.size();
        vector<int> odd(total, 0), even(total, 0);
        if (arr[0] % 2)
            odd[0] = 1;
        else
            even[0] = 1;

        for (int i = 1; i < total; i++)
        {
            if (arr[i] % 2)
            {
                odd[i] = (even[i - 1] + 1 + odd[i - 1]) % mod;
                even[i] = (odd[i - 1] + even[i - 1]) % mod;
            }
            else
            {
                even[i] = (2 * even[i - 1] + 1) % mod;
                odd[i] = (2 * odd[i - 1]) % mod;
            }
        }
        for (auto x : even)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : odd)
        {
            cout << x << " ";
        }
        cout << endl
             << endl;
        return odd[total - 1];
    }
};