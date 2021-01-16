#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6;
const int mod = 1000000007;
int len, res;

string s;
int candidate[mx];
stack<int> SS;

void TRY(int k)
{
    // cout << "TRYING ON " << k << endl;
    if (k == len)
    {
        if (SS.empty())
            res++;
        cout << "HI";
        return;
        // cout << endl;
        // stack<int> S;
        // for (int i = 0; i < len; i++)
        // {
        //     if (candidate[i] == -1)
        //     {
        //         if (S.empty())
        //         {
        //             return;
        //         }

        //         if (S.top() != 1)
        //         {
        //             return;
        //         }
        //         S.pop();
        //     }
        //     else
        //     {
        //         S.push(candidate[i]);
        //     }
        // }
        // if (S.empty())
        //     res++;

        // return;
    }

    if (s[k] == '(')
    {
        candidate[k] = 1;
        SS.push(1);
        TRY(k + 1);
        SS.pop();
    }
    else if (s[k] == ')')
    {
        if (SS.top() == -1)
            return;
        SS.pop();
        candidate[k] = -1;
        TRY(k + 1);
        SS.push(1);
    }
    else if (s[k] == '?')
    {
        SS.push(1);
        candidate[k] = 1;
        TRY(k + 1);
        SS.pop();

        if (SS.top() == 1)
        {
            SS.pop();
            candidate[k] = -1;
            TRY(k + 1);
            SS.push(1);
        }

        candidate[k] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    len = s.size();
    TRY(0);
    cout << res;
}


