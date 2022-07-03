class Solution
{
public:
    void dfs(int v, vector<int> &visited, vector<int> &nums, vector<vector<int>> &edges, int M, int N, int xr, vector<int> & xrs)
    {
        visited[v] = 1;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
        {
            if (i == M)
                continue;
            if (i == N)
                continue;

            if (edges[i][0] == v)
            {
                if (!visited[edges[i][1]])
                {
                    dfs(edges[i][1], visited, nums, edges, M, N, xr^nums[v], xrs);
                    cnt++;
                }
            }
            else if (edges[i][1] == v)
            {
                if (!visited[edges[i][0]])
                {
                    dfs(edges[i][0], visited, nums, edges, M, N, xr^nums[v], xrs);
                    cnt++;
                }
            }
        }
        if (!cnt){
            xrs.push_back(xr^nums[v]);
            // cout << "OK";
        }
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        int diff = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                vector<int> visited(n, 0);
                vector<int> xrs;

                dfs(edges[i][0], visited, nums, edges, i, j, 0, xrs);
                dfs(edges[i][1], visited, nums, edges, i, j, 0, xrs);
                
                if (!visited[edges[j][0]])
                {
                    dfs(edges[j][0], visited, nums, edges, i, j, 0, xrs);
                }
                
                if (!visited[edges[j][1]])
                {
                    dfs(edges[j][1], visited, nums, edges, i, j, 0, xrs);
                }

                diff = min(diff, *max_element(xrs.begin(), xrs.end()) - *min_element(xrs.begin(), xrs.end()));
            }
        }
        return diff;
    }
};