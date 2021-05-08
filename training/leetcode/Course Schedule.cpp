#include <bits/stdc++.h>
using namespace std;

int main()
{
}



// class Solution
// {
// public:
//     bool res = true;
//     vector<int> main_visited;
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         int n = prerequisites.size();
//         vector<vector<int>> adj(numCourses);
//         vector<int> visited(numCourses, 0);
//         main_visited = visited;
//         for (auto x : prerequisites)
//         {
//             adj[x[0]].push_back(x[1]);
//         }
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (!main_visited[i])
//                 DFS(i, adj, numCourses, visited);
//             if (!res)
//                 break;
//             cout << endl;
//         }
//         return res;
//     }
//     void DFS(int src, vector<vector<int>> &adj, int numCourses, vector<int> visited)
//     {
//         cout << src << " ";
//         visited[src] = 1;
//         main_visited[src] = 1;
//         for (auto x : adj[src])
//         {
//             if (!visited[x])
//                 DFS(x, adj, numCourses, visited);
//             else
//                 res = false;
//         }
//     }
// };