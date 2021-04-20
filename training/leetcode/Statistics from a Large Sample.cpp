#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int total = 256;
    vector<double> sampleStats(vector<int> &count)
    {
        vector<double> res;
        double minimum, maximum, mean, median, mode, mode_count = 0;
        for (int i = 0; i < total; i++)
        {
            if (count[i])
            {
                res.push_back(i);
                break;
            }
        }
        for (int i = total - 1; i >= 0; i--)
        {
            if (count[i])
            {
                res.push_back(i);
                break;
            }
        }
        double sum;
        int n = 0;
        vector<int> v;
        for (int i = 0; i < total; i++)
        {
            n += count[i];
            // for (int j = 1; j <= count[i]; j++)
            //     v.push_back(i);
        }
        int l = ceil(n / 2.0);
        int r = n + 1 - l;
        for (int i = 0; i < total; i++)
        {
            mean += (count[i] * 1.0 / n) * i;
        }

        for (int i = 0; i < total; i++)
        {

            if (count[i] > mode_count)
            {
                mode = i;
                mode_count = count[i];
            }
        }
        cout << l << " " << r << endl;
        for (int i = 0; i < total; i++)
        {

            l -= count[i];
            if (l <= 0)
            {
                l = i;
                break;
            }
        }
        for (int i = 0; i < total; i++)
        {

            r -= count[i];
            if (r <= 0)
            {
                r = i;
                break;
            }
        }
        cout << l << " " << r << endl;

        median = (l + r) / 2.;
        res.push_back(mean);
        res.push_back(median);
        res.push_back(mode);
        return res;
    }
};