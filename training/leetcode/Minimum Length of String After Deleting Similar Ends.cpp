class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> v;
        int value[100005], cnt[100005];
        memset(value, 0, sizeof(value));
        memset(cnt, 0, sizeof(cnt));

        for (auto c : s)
        {
            v.push_back(c - 'a');
        }
        int len = v.size();
        int idx = 0;
        cnt[0] = 1;
        value[0] = v[0];
        for (int i = 1; i < len; i++)
        {

            if (v[i] == v[i - 1])
                cnt[idx]++;
            else
            {
                idx++;
                cnt[idx]++;
                value[idx] = v[i];
            }
        }
        // for (int i = 0; i <= idx; i++)
        // {
        //     cout << value[i] << " " << cnt[i] << endl;
        // }
        int l = 0, r = idx;
        while (r >= l)
        {
            if (r == l)
                return cnt[l] == 1;
            if (value[r] == value[l])
            {
                r--;
                l++;
            }
            else
                break;
        }
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            res += cnt[i];
        }
        return res;
    }
};