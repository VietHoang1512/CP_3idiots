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
    int res = INF;
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {

        int total = nums1.size();
        vector<int> visited(total), cur;

        TRY(nums1, nums2, 0, visited, cur);
        return res;
    }
    void TRY(vector<int> &nums1, vector<int> &nums2, int k, vector<int> &visited, vector<int> &cur)
    {
        int total = nums1.size();

        if (k == total)
        {
            int tmp = 0;
            for (int i = 0; i < total; i++)
            {
                tmp += nums1[i] ^ cur[i];
            }
            res = min(res, tmp);
            return;
        }
        for (int i = 0; i < total; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                cur.push_back(nums2[i]);
                TRY(nums1, nums2, k + 1, visited, cur);
                visited[i] = 0;
                cur.pop_back();
            }
        }
    }
};

int main()
{
}
