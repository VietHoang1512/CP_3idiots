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
    ListNode(int x) : val(x), next(NULL) {}
};
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int cntA = 0, cntB = 0;
        ListNode *cur = headA;
        while (cur != NULL)
        {
            cur = cur->next;
            cntA++;
        }
        cur = headB;
        while (cur != NULL)
        {
            cur = cur->next;
            cntB++;
        }
        while (cntA > cntB)
        {
            cntA--;
            headA = headA->next;
        }
        while (cntB > cntA)
        {
            cntB--;
            headB = headB->next;
        }
        while (1)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};