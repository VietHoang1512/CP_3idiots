#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int cnt=1;
        queue<TreeNode *> q;
        if (root->left == NULL)
            return root;
   
        if (root->left->left == NULL ){
          int tmp = root->left->val;
        root->left->val = root->right->val;
        root->right->val = tmp;               
            return root;
        }
            
        q.push(root->left);
        q.push(root->right);
        TreeNode *l=NULL, *r=NULL;
        while (!q.empty())
        {
            cnt+=2;
            l = q.front();
            q.pop();
            r = q.front();
            q.pop();
            int log = log2(cnt);
            // cout << cnt << " " << l->val << " " << r-> val << endl;
            if(log%2==1){
                int tmp = l->val;
                l->val = r->val;
                r->val = tmp;
            }
            if (l->left != NULL)
            {
                q.push(l->left);
                q.push(r->right);
                q.push(l->right);
                q.push(r->left);
            }
        }
        // cout << "\n***\n";
        return root;
    }
};