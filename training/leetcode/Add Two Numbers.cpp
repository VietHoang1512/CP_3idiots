#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int add = 0;
        ListNode res(0);
        ListNode *cur = &res, *res_id=&res;
        ListNode *cur1 = l1, *cur2 = l2;
        while (cur1 != NULL || cur2 != NULL)
        {
            int tmp = add;
            if (cur1 != NULL)
            {
                tmp += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != NULL)
            {
                tmp += cur2->val;
                cur2 = cur2->next;
            }
            add = tmp / 10;
            tmp %= 10;
            cur->next = new ListNode(tmp);
            cur = cur->next;
            cout << tmp << " ";
        }
        if (add)
            cur->next = new ListNode(add);
        cout << add << endl;
        return res.next;
    }
};