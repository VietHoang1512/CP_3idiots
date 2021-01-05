// #include <iostream>
using namespace std;
// #include <string.h>
// #include <stack>
#include <bits/stdc++.h>

int par(string str)
{   
    // cout << "ngu";
    int a = str.size();
    stack<char> S;
    char x, y;
    for (int i = 0; i < a; i++)
    {
        x = str[i];
        if ((x == '(') || (x == '[') || (x == '{'))
        {
            S.push(x);
        }
        else
        {
            if (x == ')')
            {
                if (S.top() == '(')
                {
                    S.pop();
                }
                else
                    return 0;
            }
            else if (x == ']')
            {
                if (S.top() == '[')
                {
                    S.pop();
                }
                else
                    return 0;
            }
            else if (x == '}')
            {
                if (S.top() == '{')
                {
                    S.pop();
                }
                else
                    return 0;
            }
        }
    }
    if (S.size())
    {
        return 0;
    }
    else
        return 1;
    return 1;
}

int main()
{
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        cout << par(str) << endl;
    }
    // cout << "DONE";
    return 0;
}