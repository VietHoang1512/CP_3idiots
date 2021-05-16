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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int len1 = 0, len2 = 0;

        ListNode *cur = list1;
        while (cur != NULL)
        {
            len1++;
            cur = cur->next;
        }

        cur = list2;
        ListNode *Last;
        while (cur != NULL)
        {
            len2++;

            if (cur->next == NULL)
                Last = cur;
            cur = cur->next;
        }

        int new_len = len1 + len2 - (b - a + 1);
        int cnt = 0;
        cur = list1;
        ListNode *aNode, *bNode;
        while (cur != NULL)
        {
            if (cnt == a - 1)
                aNode = cur;
            if (cnt == b + 1)
                bNode = cur;
            cur = cur->next;
            cnt++;
        }
        aNode->next = list2;
        Last->next = bNode;
        if (a == 0)
            return aNode;
        return list1;
    }
};