/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int max_by_depth[10005], graph_depth = 0;
    int int_min = -pow(2, 31);
    vector<int> largestValues(TreeNode *root)
    {
        for (int i = 0; i < 10005; i++)
        {
            max_by_depth[i] = int_min;
        }

        vector<int> res;
        if (!root)
            return res;
        dfs(root, 0);
        for (int i = 0; i <= graph_depth; i++)
        {
            res.push_back(max_by_depth[i]);
        }
        return res;
    }
    void dfs(TreeNode *root, int depth)
    {
        graph_depth = max(graph_depth, depth);
        max_by_depth[depth] = max(max_by_depth[depth], root->val);
        if (root->left)
            dfs(root->left, depth + 1);
        if (root->right)
            dfs(root->right, depth + 1);
    }
};