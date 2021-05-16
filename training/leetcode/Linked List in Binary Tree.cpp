#include <bits/stdc++.h>
using namespace std;

int main()
{
}

/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution
{
public:
    bool res = false;
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        // cout << "\n\n";
        vector<int> path;
        while (head != NULL)
        {
            path.push_back(head->val);
            head = head->next;
        }
        vector<int> cur_path;
        DFS(root, cur_path, path);
        return res;
    }
    void DFS(TreeNode *root, vector<int> cur_path, vector<int> &path)
    {
        cur_path.push_back(root->val);
        // cout << "Visiting " << root->val << ":";
        // for (auto x : cur_path)
        // {
        //     cout << " " << x;
        // }
        // cout << endl;

        if ((cur_path.size() >= path.size()))
        {
            int total = path.size();
            vector<int> tmp(cur_path.end() - total, cur_path.end());
            if (tmp == path)
                res = true;
        }
        if (root->left != NULL)
        {
            DFS(root->left, cur_path, path);
        }
        if (root->right != NULL)
        {
            DFS(root->right, cur_path, path);
        }
    }
};