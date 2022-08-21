#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int len = pattern.size();
        vector<int> v(len);
        int cnt = 0, cur = 0;
        for (int i = 0; i < len; i++)
        {
            if (pattern[i] == 'D')
            {
                if(!cnt) cur++;
                cnt++;
                
            }
            if (pattern[i] == 'I')
            {
                if (cnt)
                    v[cur] = cnt;
                cur++;
                cnt = 0;
            }
            if (i == len - 1)
                v[cur] = cnt;
        }
        for (int i = 0; i < len; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n\n";
        vector<int> res(len + 1);
        for (int i = 1; i <= len + 1; i++)
        {
            res[i - 1] = i;
        }
        for (int i = 0; i < len; i++)
        {
            if (v[i])
                reverse(res.begin() + i, res.begin() + i + v[i] + 1);
        }
        string ans = "";
        for (int i = 0; i <= len; i++)
        {
            ans += to_string(res[i]);
        }
        return ans;
    }
};