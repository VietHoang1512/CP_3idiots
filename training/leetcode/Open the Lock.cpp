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
#define MOD 10

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
    int dp[10][10][10][10];
    int openLock(vector<string> &deadends, string target)
    {
        MEM(dp, 0);

        VI cur(4), des;

        FORAUTO(c, target)
        {
            des.push_back(c - '0');
        }
        FORAUTO(d, deadends)
        {
            dp[d[0] - '0'][d[1] - '0'][d[2] - '0'][d[3] - '0'] = INF;
        }

        queue<VI> Q;
        Q.push(cur);
        while (Q.size())
        {
            VI u = Q.front();
            
            int dist = dp[u[0]][u[1]][u[2]][u[3]];
            Q.pop();
            if (dist == INF)
                continue;
            REP(i, 4)
            {
                u[i] = (u[i] + 1) % MOD;
                int tmp = dp[u[0]][u[1]][u[2]][u[3]];
                if ((!tmp) && (*max_element(all(u))))
                {
                    dp[u[0]][u[1]][u[2]][u[3]] = dist + 1;
                    cout << u[0] << " " << u[1] << " " << u[2] << " " << u[3] << "->" << dist+1 << endl;
                    Q.push(u);
                }
                u[i] = (u[i] + 8) % MOD;
                if ((!tmp) && (*max_element(all(u))))
                {
                    dp[u[0]][u[1]][u[2]][u[3]] = dist + 1;
                    cout << u[0] << " " << u[1] << " " << u[2] << " " << u[3] << "->" << dist+1 << endl;
                    Q.push(u);
                }
                u[i] = (u[i]+1)%MOD;
            }
        }

        // DFS(cur, des, 0);
        int res = dp[des[0]][des[1]][des[2]][des[3]];
        if ((!res) || (res >= INF))
            return -1;
        return res;
    }
    // void DFS(VI cur, VI &des, int dist)
    // {
    //     cout << cur[0] << " " << cur[1] << " " << cur[2] << " " << cur[3] << "->" << dist << endl;
    //     // if (dp[cur[0]][cur[1]][cur[2]][cur[3]])
    //     // {
    //     //     if (cur == des)
    //     //     {
    //     //         dp[cur[0]][cur[1]][cur[2]][cur[3]] = min(dp[cur[0]][cur[1]][cur[2]][cur[3]], dist);
    //     //     }
    //     //     else
    //     //         return;
    //     // }
    //     if (cur == des)
    //     {
    //         dp[cur[0]][cur[1]][cur[2]][cur[3]] = dist;
    //         return;
    //     }
    //     // if (*max_element(all(cur)) == 0)
    //     //     return;

    //     dp[cur[0]][cur[1]][cur[2]][cur[3]] = dist;
    //     REP(i, 4)
    //     {
    //         cur[i] = (cur[i] + 1) % MOD;
    //         if ((!dp[cur[0]][cur[1]][cur[2]][cur[3]]) && (*max_element(all(cur))))
    //             DFS(cur, des, dist + 1);
    //         cur[i] = (cur[i] +8) % MOD;
    //         if ((!dp[cur[0]][cur[1]][cur[2]][cur[3]]) && (*max_element(all(cur))))
    //             DFS(cur, des, dist + 1);
    //     }
    // }
};

int main()
{
}
