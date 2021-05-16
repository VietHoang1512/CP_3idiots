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
    int result = 0;
    int maxDistance;
    int countPairs(TreeNode *root, int distance)
    {
        // cout << endl
        //      << endl;
        maxDistance = distance;
        DFS(root);
        return result;
    }

    vector<vector<int>> DFS(TreeNode *root)
    {
        vector<int> left(maxDistance, 0), right(maxDistance, 0);
        if (root == NULL)
        {
            // cout << "\nNode: " << root->val << endl;
            return {left, right};
        }

        else
        {

            if (root->left != NULL)
            {
                if (root->left->left == NULL && root->left->right == NULL)
                    left[0] = 1;
                vector<vector<int>> tmp = DFS(root->left);
                for (int i = 0; i < maxDistance - 1; i++)
                {
                    left[i + 1] = tmp[0][i] + tmp[1][i];
                }
            }

            if (root->right != NULL)
            {
                                if (root->right->left == NULL && root->right->right == NULL)
                right[0] = 1;
                vector<vector<int>> tmp = DFS(root->right);
                for (int i = 0; i < maxDistance - 1; i++)
                {
                    right[i + 1] = tmp[0][i] + tmp[1][i];
                }
            }
        }
        // cout << "\nNode: " << root->val << endl;

        for (int i = 0; i < maxDistance; i++)
        {
            for (int j = 0; j < maxDistance; j++)
            {
                if (i + j + 2 <= maxDistance)
                {
                    result += (left[i] * right[j]);
                    // cout << "Added " << (left[i] * right[j]) << "(" << i << "-" << j << ") ";
                }
            }
        }
        // cout << endl;
        // cout << "LEFT: ";
        // for (auto x : left)
        // {
        //     cout << x << " ";
        // }
        // cout << "\nRIGHT: ";
        // for (auto x : right)
        // {
        //     cout << x << " ";
        // }
        return {left, right};
    }
};