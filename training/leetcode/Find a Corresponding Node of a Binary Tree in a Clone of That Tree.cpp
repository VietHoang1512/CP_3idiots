/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        const int mx = 2e4;
        set<TreeNode *> s;
        queue<TreeNode *> original_q, cloned_q;
        original_q.push(original);
        cloned_q.push(cloned);
        cout << original_q.size();
        while (original_q.size())
        {

            TreeNode *v = original_q.front();
            TreeNode *u = cloned_q.front();
            original_q.pop();
            cloned_q.pop();
            if (u->val == target->val)
                return u;
            if (v->left)
            {
                original_q.push(v->left);
                cloned_q.push(u->left);
            }
            if (v->right)
            {
                original_q.push(v->right);
                cloned_q.push(u->right);
            }
        }

        return original;
    }
};