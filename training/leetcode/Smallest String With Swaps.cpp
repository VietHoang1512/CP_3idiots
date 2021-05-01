#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mx = 1e5 + 5;
class Solution
{
public:
    int parent[mx];
    int cnt_idx[mx];
    vector<int> cnt2vec[mx];
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int total = s.size();
        for (int i = 0; i < total; i++)
        {
            parent[i] = i;
        }
        for (vector<int> pair : pairs)
        {
            Union(parent, pair[0], pair[1]);
        }
        // cout << "Parents: ";
        int mx_parent = 0;
        for (int i = 0; i < total; i++)
        {
            mx_parent = max(mx_parent, Find(parent, i));
        }
        for (int i = 0; i < total; i++)
        {
            // cout << parent[i] << " ";
            cnt2vec[parent[i]].push_back(s[i] - 'a');
        }

        for (int i = 0; i <= mx_parent; i++)
        {
            sort(cnt2vec[i].begin(), cnt2vec[i].end());
        }
        string res;
        for (int i = 0; i < total; i++)
        {
            int parent_ = parent[i];
            res += ('a' + cnt2vec[parent_][cnt_idx[parent_]]);
            cnt_idx[parent_]++;
        }
        // cout << res;

        return res;
    }

    int Find(int parent[], int i)
    {
        if (parent[i] == i)
            return i;
        parent[i] = Find(parent, parent[i]);
        return parent[i];
    }
    void Union(int parent[], int x, int y)
    {
        int parent_x = Find(parent, x), parent_y = Find(parent, y);
        parent[max(parent_x, parent_y)] = min(parent_x, parent_y);
    }
};
