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
    int calculate_offsprint_value(TreeNode *v)
    {
        int res = 0;
        if (v->right)
        {
            if (v->right->right)
                res += v->right->right->val;
            if (v->right->left)
                res += v->right->left->val;
        }
        if (v->left)
        {
            if (v->left->right)
                res += v->left->right->val;
            if (v->left->left)
                res += v->left->left->val;
        }
        return res;
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        int res = 0;
        queue<TreeNode *> q;

        q.push(root);
        while (q.size())
        {
            TreeNode *v = q.front();
            q.pop();
            if (!(v->val % 2))
                res += calculate_offsprint_value(v);
            if (v->left)
                q.push(v->left);
            if (v->right)
                q.push(v->right);
        }
        return res;
    }
};