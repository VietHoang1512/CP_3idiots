#include <bits/stdc++.h>
using namespace std;

int main()
{
}

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
    int res;
    vector<vector<int>> path;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> cur_path;
        DFS(root, targetSum, 0, cur_path);
        return path;
    }

    void DFS(TreeNode *root, int targetSum, int cur, vector<int> cur_path)
    {
        if (root == NULL)
            return;
        cur += root->val;
        cur_path.push_back(root->val);
        if (root->left != NULL)
        {
            DFS(root->left, targetSum, cur, cur_path);
        }
        if (root->right != NULL)
        {
            DFS(root->right, targetSum, cur, cur_path);
        }
        if ((root->left == NULL) && (root->right == NULL))
        {
            if (cur == targetSum)
            {
                path.push_back(cur_path);
            }
        }
    }
};