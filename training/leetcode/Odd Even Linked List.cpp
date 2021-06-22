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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = head, *even = head;
        int cnt_odd = 0, cnt_even = 0;
        while (odd->next != NULL && (odd->val % 2 == 0))
        {
            odd = odd->next;
            cnt_odd++;
        }
        while (even->next != NULL && (even->val % 2))
        {
            even = even->next;
            cnt_even++;
        }
        ListNode *cur, *head_odd = odd, *head_even = even;
        cout << head_odd->val << " " << head_even->val << endl;
        while ((odd->next != NULL) && (odd->next->val % 2))
        {
            odd = odd->next;
            cnt_odd++;
        }
        while ((even->next != NULL) && ((even->next->val % 2) == 0))
        {
            even = even->next;
            cnt_even++;
        }
        if (cnt_odd > cnt_even)
        {
            cur = odd->next;
        }
        else
            cur = even->next;

        while (cur != NULL)
        {
            if (cur->val % 2)
            {
                odd->next = cur;
                odd = cur;
            }
            else
            {
                even->next = cur;
                even = cur;
            }
            cur = cur->next;
        }
        even->next = NULL;
        odd->next = head_even;

        return head_odd;
        // while (even != NULL)
        // {
        //     if (((odd->val % 2) == 0) && (even->val % 2))
        //     {
        //         swap(odd->val, even->val);
        //         even = even->next;
        //         odd = odd->next;
        //         continue;
        //     }
        //     if (even->val % 2 == 0)
        //     {
        //         even = even->next;
        //         continue;
        //     }
        //     if ((odd->val % 2) && (odd->next != even))
        //     {
        //         odd = odd->next;
        //         continue;
        //     }

        //     even = even->next;
        //     odd = odd->next;
        // }
    }
};