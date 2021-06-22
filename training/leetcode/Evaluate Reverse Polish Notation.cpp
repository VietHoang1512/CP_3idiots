#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto t : tokens)
        {
            if (t == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (t == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }
            else if (t == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (t == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else
                s.push(stoi(t));
        }
        return s.top();
    }
};