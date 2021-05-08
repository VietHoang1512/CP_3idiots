#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        cout << "\n\n";
        int len1 = nums1.size(), len2 = nums2.size();
        int sum1 = 0;
        int sum2 = 0;
        vector<int> cnt1(7, 0), cnt2(7, 0);

        for (auto x : nums1)
        {
            sum1 += x;
            cnt1[x]++;
        }

        for (auto x : nums2)
        {
            sum2 += x;
            cnt2[x]++;
        }

        if (sum1 > sum2)
        {
            vector<int> v = cnt1;
            cnt1 = cnt2;
            cnt2 = v;

            int s = sum1;
            sum1 = sum2;
            sum2 = s;
            cout << "Reversed\n";
        }
        cout << "S1: ";
        for (int i = 1; i <= 6; i++)
        {
            cout << cnt1[i] << " ";
        }
        cout << "\nS2: ";
        for (int i = 1; i <= 6; i++)
        {
            cout << cnt2[i] << " ";
        }
        cout << endl;
        int res = 0;
        while (sum2 > sum1)
        {
            int tmp = sum2 - sum1;
            for (int i = 1; i <= 6; i++)
            {
                if (cnt1[i] || cnt2[7 - i])
                {
                    if (cnt1[i])
                    {

                        cnt1[i]--;
                        int diff = min(6 - i, tmp);
                        sum1 += diff;
                        cnt1[i + diff]++;
                        res++;
                        cout << "S1 " << i << "->" << i + diff << endl;
                        break;
                    }
                    else
                    {
                        cnt2[7 - i]--;
                        int diff = min(6 - i, tmp);
                        sum2 -= diff;
                        cnt2[7 - i - diff]++;
                        res++;
                        cout << "S2 " << 7 - i << "->" << 7 - i - diff << endl;

                        break;
                    }
                }
            }
            cout << "Current difference " << (sum2 - sum1) << endl;
            if ((sum2 - sum1) == tmp)
                return -1;
        }
        return res;
    }
};