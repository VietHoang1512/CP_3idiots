#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        cout << "\n\n";
        sort(arr.begin(), arr.end());
        int total = arr.size();
        int res = 1;
        if (arr[0] > 1)
        {
            arr[0] = 1;
        }
        for (int i = 1; i < total; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr[total - 1];
    }
};