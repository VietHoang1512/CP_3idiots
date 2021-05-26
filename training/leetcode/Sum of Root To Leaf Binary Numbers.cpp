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
    int res = 0;
    int sumRootToLeaf(TreeNode *root)
    {
        // cout << "\n";
        vector<int> path;
        DFS(root, path);
        return res;
    }

    void DFS(TreeNode *root, vector<int> path)
    {
        // cout << "->" << root->val;
        path.push_back(root->val);
        if (root->right == NULL && root->left == NULL)
        {
            res += cal(path);
            return;
        }
        if (root->left != NULL)
            DFS(root->left, path);
        if (root->right != NULL)
            DFS(root->right, path);
        path.pop_back();
    }

    int cal(vector<int> path)
    {
        reverse(path.begin(), path.end());
        int r = 0;
        // cout << "\npath: ";
        for (int i = 0; i < path.size(); i++)
        {
            // cout << path[i] << " ";
            r += (1 << i) * path[i];
        }
        // cout << ": " << r << endl;
        return r;
    }
};