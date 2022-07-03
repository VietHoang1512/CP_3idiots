#include <bits/stdc++.h>
using namespace std;

int main()
{
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> candidates;
        candidates.push_back({0, 1});
        candidates.push_back({1, 0});
        candidates.push_back({0, -1});
        candidates.push_back({-1, 0});
        int r = 0, c = 0, d = 0;

        for (int i = 0; i < m * n; i++)
        {
            if (head == NULL)
                break;
            matrix[r][c] = head->val;

            head = head->next;
            // cout << " (" << r << " " << c <<") ";
            visited[r][c] = 1;
            int next_r = r + candidates[d].first;
            int next_c = c + candidates[d].second;

            if (0 <= next_r && next_r < m && 0 <= next_c && next_c < n && !visited[next_r][next_c])
            {
                r = next_r;
                c = next_c;
            }
            else
            {
                d++;
                d %= 4;
                r += candidates[d].first;
                c += candidates[d].second;
                // cout<<"\nchange direction!\n";
            }
        }
        // cout <<"\n****\n";
        return matrix;
    }
};