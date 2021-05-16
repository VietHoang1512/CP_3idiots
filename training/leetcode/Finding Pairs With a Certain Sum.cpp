#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class FindSumPairs
{
public:
    vector<int> n1, n2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        n1 = nums1;
        for (auto x : nums2)
        {
            m[x]++;
        }
        n2 = nums2;
    }

    void add(int index, int val)
    {
        m[n2[index]]--;
        n2[index] += val;
        m[n2[index]]++;
    }

    int count(int tot)
    {
        int res = 0;
        vector<int> nums2 = n2;

        for (auto x : n1)
        {

            res += m[tot - x];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */