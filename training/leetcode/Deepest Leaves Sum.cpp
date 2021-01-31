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
    int graph_depth = 0;
    int sum_by_depth[10005];
    int deepestLeavesSum(TreeNode *root)
    {
        memset(sum_by_depth, 0, sizeof(sum_by_depth));
        dfs(root, 0);

        return sum_by_depth[graph_depth];
    }
    void dfs(TreeNode *v, int depth)
    {
        graph_depth = max(graph_depth, depth);
        sum_by_depth[depth] += v->val;
        if (v->left)
            dfs(v->left, depth + 1);
        if (v->right)
            dfs(v->right, depth + 1);
    }
};