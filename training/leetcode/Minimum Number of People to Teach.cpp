#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        vector<vector<int>> adj(vector<int>(n, 0));
        for (auto x : friendships)
        {
            adj[x[0]][x[1]] = adj[x[1]][x[0]] = 1;
        }
    }
};