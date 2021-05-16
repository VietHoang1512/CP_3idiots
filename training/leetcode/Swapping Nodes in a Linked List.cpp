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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int len = 1;
        ListNode *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
            len++;
        }
        // cout << "\n Length: " << len << endl;
        if (len == 1)
            return head;

        k = min(k, len + 1 - k);
        cur = head;
        int l, r;
        for (int i = 1; i <= len; i++)
        {
            // cout << i << "-" << cur->val << " ";
            if (i == k)
                l = cur->val;
            if (i == len + 1 - k)
                r = cur->val;
            cur = cur->next;
        }
        cur = head;
        for (int i = 1; i <= len; i++)
        {
            if (i == k)
                cur->val = r;
            if (i == len + 1 - k)
                cur->val = l;
            cur = cur->next;
        }
        return head;
    }
};