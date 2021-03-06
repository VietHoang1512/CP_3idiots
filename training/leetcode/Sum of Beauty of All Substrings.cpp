#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int beautySum(string s)
    {
        int mx = 600;
        int total = s.size();
        int n_char = 'z' - 'a' + 1;
        int cnt[n_char][mx], cur[n_char];
        int res = 0;
        memset(cur, 0, sizeof(cur));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < total; i++)
        {
            int tmp = s[i] - 'a';
            cur[tmp]++;
            for (int j = 0; j < n_char; j++)
            {
                cnt[j][i] = cur[j];
            }
        }
        for (int i = 0; i + 1 < total; i++)
        {

            for (int j = i + 1; j < total; j++)
            {
                int max_ = 0, min_ = total;

                for (int k = 0; k < n_char; k++)
                {
                    int tmp = cnt[k][j] - cnt[k][i];
                    max_ = max(tmp, max_);
                    min_ = min(tmp, min_);
                }
                res += max_ - min_;
                if (max_ - min_)
                {
                    cout << i << " " << j << " " << max_ << " " << min_ << endl;
                }
            }
            cout << endl;
        }
        return res;
    }
};