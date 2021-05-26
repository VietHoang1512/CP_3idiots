#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        // cout << "\n*****\n";
        int l = 1, r = INT_MAX/2;

        if (dist.size() > hour + 1)
            return -1;
        while (r > l)
        {
            int tmp = (r + l) / 2;
            // cout << tmp << " " << l << " " << r << " ->  ";
            if (CHECK(dist, hour, tmp))
            {
                // cout << " (OK) ";
                r = tmp;
            }

            else
                l = tmp;

            // cout << tmp << " " << l << " " << r << endl;
            if (r == l + 1)
            {
                if (CHECK(dist, hour, l))
                    return l;
                break;
            }
        }

        return r;
    }
    bool CHECK(vector<int> &dist, double hour, int speed)
    {
        double res = 0;
        for (auto d : dist)
        {
            res = ceil(res);
            res +=(d + 0.0) / speed;
        }
        return res <= hour;
    }
};