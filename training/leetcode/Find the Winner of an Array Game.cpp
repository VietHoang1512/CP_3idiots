#include <bits/stdc++.h>
using namespace std;

int main()
{
}


class Solution
{
public:
    int shift = 0;
    int getWinner(vector<int> &arr, int k)
    {

        shift = 0;
        // cout << "****************************\n";
        int total = arr.size();
        int cnt = 0;
        int cur = 0;
        int prev = max(arr[0], arr[1]);
        int mx = *max_element(arr.begin(), arr.end());
        if (k > total)
            return mx;
        // for (int i = 0; i < total; i++)
        // {
        //     cout << Get(arr, i) << " ";
        // }
        // cout << "\n\n";
        while (cur < k)
        {
            // cout << cnt++ << endl;
            if (Get(arr, 0) < Get(arr, 1))

            {
                int tmp = Get(arr, 1);
                Set(arr, 1, Get(arr, 0));
                Set(arr, 0, tmp);
            }
            if (prev == arr[0])
                cur++;
            else cur=1;
            prev = arr[0];
            shift++;
            // for (int i = 0; i < total; i++)
            // {
            //     cout << Get(arr, i) << " ";
            // }
            // cout << "\n\n";
            cout << prev << endl;
        }
        return arr[0];
    }
    int Get(vector<int> &arr, int k)
    {
        int total = arr.size();
        if (k == 0)
            return arr[0];
        return arr[1 + (k - 1 + shift) % (total - 1)];
    }
    void Set(vector<int> &arr, int k, int v)
    {
        int total = arr.size();

        if (k == 0)
            arr[0] = v;
        else
            arr[1 + (k - 1 + shift) % (total - 1)] = v;
    }
};


// [2,1,3,5,4,6,7]
// 2
// [3,2,1]
// 10
// [1,9,8,2,3,7,6,4,5]
// 7
// [1,11,22,33,44,55,66,77,88,99]
// 1000000000
// [1,25,35,42,68,70]
// 1
// [31,683,544,163,384,470,580,66,84,249,9,659,555,107,699,927,549,346,820,126,219,121,653,513,201,641,865,970,838,684,822,14,196,994,692,329,150,398,43,615,321,120,184,190,742,810,427,535,971,448,180,933,756,955,969,495,383,401,666]
// 14