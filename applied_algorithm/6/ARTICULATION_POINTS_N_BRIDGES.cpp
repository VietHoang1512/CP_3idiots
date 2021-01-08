#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;
int n, m;
vector<int> a[N];
int CriticalEdge = 0;
bool CriticalNode[N];
int Num[N], Low[N], Time = 0;

void visit(int u, int p)
{
    int NumChild = 0;
    Low[u] = Num[u] = ++Time;
    for (int v : a[u])
        if (v != p)
        {
            if (Num[v] != 0)
                Low[u] = min(Low[u], Num[v]);
            else
            {
                visit(v, u);
                NumChild++;
                Low[u] = min(Low[u], Low[v]);

                if (Low[v] >= Num[v])
                    CriticalEdge++;

                if (u == p)
                {
                    if (NumChild >= 2)
                        CriticalNode[u] = true;
                }
                else
                {
                    if (Low[v] >= Num[u])
                        CriticalNode[u] = true;
                }
            }
        }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (!Num[i])
            visit(i, i);

    int Count = 0;
    for (int i = 1; i <= n; i++)
        Count += CriticalNode[i];

    printf("%d %d\n", Count, CriticalEdge);
}

// #include <bits/stdc++.h>

// using namespace std;

// const int mx = 1e5 + 5;

// int N, M;
// int u, v;
// vector<int> adj[mx];
// int low[mx], num[mx], curnum = 0;
// vector<pair<int, int>> bridges;

// void find_bridges(int u, int p)
// {
//     low[u] = num[u] = curnum++;
//     for (auto v: adj[u])
//     {
//         if (v == p)
//             continue;
//         if (num[v] == -1)
//         {
//             find_bridges(v, u);
//             low[u] = min(low[u], low[v]);
//         }
//         else
//         {
//             low[u] = min(low[u], num[v]);
//         }
//         if (low[v] > num[u])
//         {
//             bridges.push_back(make_pair(u, v));
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> N >> M;
//     for (int i = 1; i <= M; i++)
//     {
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     memset(num, -1, sizeof(num));

//     for (int u = 1; u <= N; u++)
//     {
//         if (num[u] == -1)
//             find_bridges(u, -1);
//     }

//     // cout << endl;
//     cout << bridges.size();
// }