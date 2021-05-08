#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int total = arr.size();
        int l = 0, r = *max_element(arr.begin(), arr.end());
        cout << "\n****\n";
        while (r > l)
        {
            int tmp1 = l + (r - l) / 3;
            int tmp2 = l + (r - l) * 2 / 3;

            cout << l << "-" << r << "-" << tmp1 << "-" << tmp2;
            cout << " got " << findDifference(arr, target, tmp1) << " and " << findDifference(arr, target, tmp2);
            if (findDifference(arr, target, tmp1) >= findDifference(arr, target, tmp2))
            {

                l = tmp1;
                cout << "->left\n";
            }
            else if (findDifference(arr, target, tmp1) < findDifference(arr, target, tmp2))
            {
                r = tmp2;
                cout << "->right\n";
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            if (r - l == 2)
            {
                for(int i=l;i<=r; i++)
                    pq.push({findDifference(arr, target, i), i});
                return pq.top().second;
            }
        }
        return l;
    }
    int findDifference(vector<int> v, int target, int value)
    {
        vector<int> arr = v;
        int total = arr.size();

        for (int i = 0; i < total; i++)
        {
            arr[i] = min(arr[i], value);
        }
        return abs(accumulate(arr.begin(), arr.end(), 0) - target);
    }
};