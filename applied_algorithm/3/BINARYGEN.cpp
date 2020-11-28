#include <bits/stdc++.h>
using namespace std;
int n, bin[10000], tmp = 1;
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        bin[i] = s[i] - '0';
        // cout << bin[i] << " ";
        tmp = min(tmp, bin[i]);
    }

    if (tmp)
    {
        cout << -1;
        return 0;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (bin[i])
        {
            bin[i] = 0;
        }
        else if (!bin[i])
        {
            bin[i] = 1;
            break;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        cout << bin[i];
    }
}