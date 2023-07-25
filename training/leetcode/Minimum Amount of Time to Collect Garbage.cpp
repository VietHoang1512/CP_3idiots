#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int n = travel.size(), mx_metal = 0, mx_paper = 0, mx_glass = 0;
        vector<int> metal(n + 1, 0), paper(n + 1, 0), glass(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            metal[i] = count(garbage[i].begin(), garbage[i].end(), 'M');
            paper[i] = count(garbage[i].begin(), garbage[i].end(), 'P');
            glass[i] = count(garbage[i].begin(), garbage[i].end(), 'G');
            if (metal[i] > 0)
                mx_metal = i;
            if (paper[i] > 0)
                mx_paper = i;
            if (glass[i] > 0)
                mx_glass = i;
        }
        int res = 0;
        res += metal[0] + paper[0] + glass[0];
        for (int i = 1; i <= mx_metal; i++)
        {
            res += metal[i] + travel[i - 1];
        }
        for (int i = 1; i <= mx_paper; i++)
        {
            res += paper[i] + travel[i - 1];
        }
        for (int i = 1; i <= mx_glass; i++)
        {
            res += glass[i] + travel[i - 1];
        }
        return res;
    }
};