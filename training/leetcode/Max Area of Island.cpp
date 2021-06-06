#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define __builtin_popcount __builtin_popcountll
// #define SCD(t) scanf("%d", &t)
// #define SCLD(t) scanf("%ld", &t)
// #define SCLLD(t) scanf("%lld", &t)
// #define SCC(t) scanf("%c", &t)
// #define SCS(t) scanf("%s", t)
// #define SCF(t) scanf("%f", &t)
// #define SCLF(t) scanf("%lf", &t)
// #define read(type) readInt<type>()
// #define IN(A, B, C) assert(B <= A && A <= C)

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FORAUTO(e, elements) for (auto e : elements)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef map<string, int> MPSI;
typedef map<char, int> MPCI;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<VI> visited(m, VI(n));
        REP(i, m)
        {
            REP(j, n)
            {
                if (grid[i][j] && !visited[i][j])
                    res = max(res, DFS(i, j, grid, visited));
            }
        }
        return res;
    }
    int DFS(int i, int j, vector<vector<int>> &grid, vector<VI> &visited)
    {

        int m = grid.size(), n = grid[0].size();

        visited[i][j] = 1;
        int area = 1;
        if ((i > 0) && grid[i - 1][j] && !visited[i - 1][j])
        {
            area += DFS(i - 1, j, grid, visited);
        }
        if ((j > 0) && grid[i][j - 1] && !visited[i][j - 1])
        {
            area += DFS(i, j - 1, grid, visited);
        }
        if ((i < m - 1) && grid[i + 1][j] && !visited[i + 1][j])
        {
            area += DFS(i + 1, j, grid, visited);
        }
        if ((j < n - 1) && grid[i][j + 1] && !visited[i][j + 1])
        {
            area += DFS(i, j + 1, grid, visited);
        }

        return area;
    }
};

int main()
{
}
