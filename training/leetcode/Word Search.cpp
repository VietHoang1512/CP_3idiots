#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}

class Solution
{
public:
    int res = 0;

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                DFS(board, word, i, j, 1, visited);
            }
        }
        return res;
    }
    void DFS(vector<vector<char>> &board, string &word, int i, int j, int k, vector<vector<int>> &visited)
    {
        int m = board.size(), n = board[0].size();

        if (board[i][j] != word[k - 1])
            return;
        if (k == word.size())
            res = 1;
        if (k > word.size())
            return;
        visited[i][j] = 1;
        if (i > 0 && (!visited[i - 1][j]))
        {
            DFS(board, word, i - 1, j, k + 1, visited);
        }
        if (i > 0 && (!visited[i - 1][j]))
        {
            DFS(board, word, i - 1, j, k + 1, visited);
        }
        if (j > 0 && (!visited[i][j - 1]))
        {
            DFS(board, word, i, j - 1, k + 1, visited);
        }
        if (i < m - 1 && (!visited[i + 1][j]))
        {
            DFS(board, word, i + 1, j, k + 1, visited);
        }
        if (j < n - 1 && (!visited[i][j + 1]))
        {
            DFS(board, word, i, j + 1, k + 1, visited);
        }
        visited[i][j] = 0;
    }
};