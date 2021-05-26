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

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */

class Solution
{
public:
    int res = 0;
    int pseudoPalindromicPaths(TreeNode *root)
    {
        VI path;
        DFS(root, path);
        return res;
    }
    bool isPalindromic(VI v)
    {
        int total = v.size(), cnt = 0;
        MPII m;
        FORAUTO(x, v)
        {
            m[x]++;
        }
        FORAUTO(p, m)
        {
            cnt += (p.second % 2);
        }
        if (total % 2)
        {
            return cnt == 1;
        }
        return cnt == 0;
    }
    void DFS(TreeNode *root, VI &path)
    {
        path.PB(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            res += isPalindromic(path);
            path.pop_back();

            return;
        }
        if (root->left != NULL)
        {
            DFS(root->left, path);
        }
        if (root->right != NULL)
        {
            DFS(root->right, path);
        }
        path.pop_back();
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{
}
