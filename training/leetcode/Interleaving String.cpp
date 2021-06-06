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
    bool isInterleave(string s1, string s2, string s3)
    {

        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();

        if (l3 - l2 - l1)
            return false;
        if (!l1)
            return s2 == s3;
        if (!l2)
            return s1 == s3;
        vector<VI> dp(l1 + 1, VI(l2 + 1));
        REP(i, l1 + 1)
        {
            REP(j, l2 + 1)
            {
                if (!i)
                {
                    dp[i][j] += (s2.substr(0, j) == s3.substr(0, j));
                    // continue;
                }
                if (!j)
                {
                    dp[i][j] += (s1.substr(0, i) == s3.substr(0, i));
                    // continue;
                }
                if (!(i * j))
                    continue;
                if (s1[i - 1] == s3[i + j - 1])
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] += dp[i][j - 1];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[l1][l2];
    }
};
int main()
{
}
