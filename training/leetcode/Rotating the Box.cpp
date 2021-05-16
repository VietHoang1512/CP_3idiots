#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        cout << "\n\n";
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++)
        {
            vector<int> v{-1};
            for (int j = 0; j < n; j++)
            {
                if (box[i][j] == '*')
                {
                    res[j][i] = '*';
                    v.push_back(j);
                }
            }
            v.push_back(n);
            int total = v.size();
            cout << res.size() <<"x"<< res[0].size() << "\n\n";
            cout << "x:v\n";
            for (auto x : v)
            {
                cout << x << " ";
            }
            cout << endl;
            for (int j = 0; j < total - 1; j++)
            {
                int cnt = 0;
                for (int k = v[j] + 1; k < v[j + 1]; k++)
                {

                    if (box[i][k] == '#')
                        cnt++;
                }
                cout << v[j] + 1 << "->" << (v[j + 1] - 1) << ": has " << cnt << endl;
                int cur = v[j + 1] - 1;
                while (cnt)
                {
                    cnt--;

                    cout << cur << " " << i << endl;
                    res[cur][i] = '#';
                    cur--;
                }
            }
        }
        return res;
    }
};