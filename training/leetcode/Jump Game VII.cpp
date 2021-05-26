#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool canReach(string &s, int minJump, int maxJump)
    {
        cout << "\n**\n";
        int total = s.size();
        vector<int> visited(total, 0);
        int cur = 0;
        DFS(s, minJump, maxJump, 0, visited);
        return visited[total - 1];
    }
    void DFS(string &s, int minJump, int maxJump, int cur, vector<int> &visited)
    {
        cout << cur << " ";
        int total = s.size();
        for (int i = cur + minJump; i <= min(cur + maxJump, total - 1); i++)
        {
            if (!visited[i])
            {
                if (s[i] == '0')
                {
                    visited[i] = 1;

                    DFS(s, minJump, maxJump, i, visited);
                    cout << endl;
                }
            }
        }
    }
};