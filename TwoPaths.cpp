#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
const int mx = 200;
vector<int> neighbor[mx], tmp;
int n;
int u, v;
bool visited_left[mx], visited_right[mx];
bool left_vertices[mx], right_vertices[mx];
int max_left, max_right;
int res = 0, max_len, max_tmp;

void find_left_vertices(int source, int excl, bool visited[])
{
    //    cout << "->" << source;
    //    cout << "\nAdd: " << source << "to left vertices" << endl;
    left_vertices[source] = true;
    visited[source] = true;
    for (int v : neighbor[source])
    {
        if (v == excl)
        {
            continue;
        }
        if (!visited[v])
        {
            find_left_vertices(v, excl, visited);
        }
    }
}
void find_right_vertices(int source, int excl, bool visited[])
{
    //    cout << "->" << source;
    //    cout << "\nAdd: " << source << "to right vertices" << endl;
    right_vertices[source] = true;
    visited[source] = true;
    for (int v : neighbor[source])
    {
        if (v == excl)
        {
            continue;
        }
        if (!visited[v])
        {
            find_right_vertices(v, excl, visited);
        }
    }
}

int find_max_dfs(int source, int excl, bool visited[])
{
    //    cout << "->" << source;
    visited[source] = true;
    int tmp = 0;
    for (int v : neighbor[source])
    {
        if (v == excl)
        {
            continue;
        }
        if (!visited[v])
        {
            tmp = max(tmp, find_max_dfs(v, excl, visited));
        }
    }
    return tmp + 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
    }
    //    cout << "Begin\n";
    for (int i = 1; i <= n; i++)
    {
        tmp = neighbor[i];
        if (tmp.size())
        {
            for (int j : tmp)
            {
                max_left = 0;
                max_right = 0;
                for (int k = 1; k <= mx; k++)
                {
                    visited_left[k] = false;
                    visited_right[k] = false;
                    left_vertices[k] = false;
                    right_vertices[k] = false;
                }
                //                cout << endl << i << " vs " << j<< endl;
                find_left_vertices(i, j, visited_left);
                find_right_vertices(j, i, visited_right);

                //                cout <<"\nFound leaves, starting find max_len" << endl;

                //                cout << "\nLEFT\n";

                for (int x = 1; x <= n; x++)
                {
                    if (left_vertices[x])
                    {
                        for (int k = 1; k <= mx; k++)
                        {
                            visited_left[k] = false;
                            visited_right[k] = false;
                        }

                        //                        cout << endl;
                        max_tmp = find_max_dfs(x, j, visited_left) - 1;
                        max_left = max(max_left, max_tmp);
                    }
                }
                //                cout << "\nRIGHT\n";
                for (int x = 1; x <= n; x++)
                {
                    if (right_vertices[x])
                    {
                        for (int k = 1; k <= mx; k++)
                        {
                            visited_left[k] = false;
                            visited_right[k] = false;
                        }

                        //                        cout << endl;
                        max_tmp = find_max_dfs(x, i, visited_right) - 1;
                        max_right = max(max_right, max_tmp);
                    }
                }
                //                cout << "\nmax_left " << max_left<< endl;
                //                cout << "\nmax_right " << max_right << endl;
                //                cout << "MAX: " << max_left*max_right << endl;
                res = max(res, max_left * max_right);
            }
        }
    }
    //    cout << "\nRESULTS:\n";
    cout << res;
}