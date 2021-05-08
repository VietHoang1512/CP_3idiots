#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)

    {
        // cout << endl;
        // cout << endl;

        int total = people.size();
        sort(people.rbegin(), people.rend());
        int l = 0, r = total - 1;
        int res = 0;
        if (total == 1)
            return 1;
        while (r > l)
        {
            ++res;
            // cout << "Ship number " << res << endl;

            int cap = limit - people[l++];
            if (cap >= people[l])
            {
                l++;
            }
            else
            {
                if (cap >= people[r])
                    r--;
            }
            if (r == l)
                return 1 + res;

            // int new_l;
            // // cout << "Left ";
            // for (int i = l; i <= r; i++)
            // {
            //     if (cap >= people[i])
            //     {
            //         cap -= people[i];
            //         new_l = i;
            //         // cout << people[i] << " ";
            //     }
            //     else
            //         break;
            // }
            // // cout << "\nRight";

            // l = new_l + 1;
            // int new_r = r + 1;
            // if (cap > 0)
            // {
            //     if (l > r)
            //         break;
            //     else
            //     {
            //         for (int i = r; i >= l; i--)
            //         {
            //             if (cap >= people[i])
            //             {
            //                 cap -= people[i];
            //                 new_r = i;
            //                 // cout << people[i] << " ";
            //             }
            //             else
            //                 break;
            //         }
            //     }
            // }
            // r = new_r - 1;
            // if (l == r)
            //     return res + 1;
            // // cout << endl;
        }
        return res;
    }
};