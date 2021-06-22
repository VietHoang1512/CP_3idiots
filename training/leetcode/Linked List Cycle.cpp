#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

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
const int mx = 1e5 + 5;
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        while (head != NULL)
        {
            if (head->val == mx)
                return true;
            head->val = mx;
            head = head->next;
        }
        return false;
    }
};