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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        ListNode *cur = head;
        if (head == NULL)
            return head;
        while (cur != NULL)
        {
            v.push_back(cur->val);
            cur = cur->next;
        }

        sort(v.begin(), v.end());
        cur = head;
        for (int i = 0; i < v.size(); i++)
        {
            cur->val = v[i];
            cur = cur->next;
        }
        return head;
    }
};