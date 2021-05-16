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
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> v_less, v_greater;
        ListNode *cur = head;

        while (cur != NULL)
        {
            if (cur->val < x)
            {
                v_less.push_back(cur->val);
            }
            else
            {
                v_greater.push_back(cur->val);
            }
            cur = cur->next;
        }
        vector<int> v;
        v.insert(v.end(), v_less.begin(), v_less.end());
        v.insert(v.end(), v_greater.begin(), v_greater.end());
        cur = head;
        for (int i = 0; i < v.size(); i++)
        {
            cur->val = v[i];
            cur = cur->next;
        }
        return head;
    }
};