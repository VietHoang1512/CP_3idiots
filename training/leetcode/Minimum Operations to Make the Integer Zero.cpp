#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        map<int, int> m, visited;
        queue<int> q;
        q.push(num1);
        m[num1] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = 0; i < 60; i++)
            {
                long long cur = v - pow(2, i) - num2;
                if ((cur >= 0) && (visited[cur]<1))
                {
                    q.push(cur);
                    visited[cur] = m[num1]+1;
                }
            }
        }
        return m[0]-1;
    }
};