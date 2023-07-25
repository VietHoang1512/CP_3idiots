#include <bits/stdc++.h>
using namespace std;

int main()
{
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<long long, long long> m;
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        traverse(root, 0);
        int len=m.size();
        if (len<k) return-1;
        vector<long long>v;
        for (auto x : m)
        {
            v.push_back(x.second);
        }
        sort(v.begin(), v.end());
        return v[len-k];
    }
    void traverse(TreeNode *root, int cur)
    {
        cur += 1;
        m[cur] += root->val;
        if (root->left != NULL)
            traverse(root->left, cur);
        if (root->right != NULL)
            traverse(root->right, cur);
    }
};