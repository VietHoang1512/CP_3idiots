#include <bits/stdc++.h>
using namespace std;
// int cur[10000];
int n, n_test;
string p;
int c = 0;
string s0 = "0", s1 = "1", tmp;
int a;
int f(int m, int m0, int m1)
{
    if (m == 0)
        return m0;
    if (m == 1)
        return m1;
    return f(m - 1, m0, m1) + f(m - 2, m0, m1);
}
int cnt(string str, string pattern)
{
    if (str.size() < pattern.size())
        return 0;
    int str_len = str.size();
    int pattern_len = pattern.size();

    int res = 0;
    for (int i = 0; i <= str_len - pattern_len; i++)
    {

        if (str.substr(i, pattern_len) == pattern)
            res++;
    }
    // cout << "res " << res << endl;
    return res;
}


int main()
{
    n_test = 0;
    while (true)
    {
        n = -1;

        n_test++;
        cin >> n >> p;
        if (n == -1)
            return 0;
        cout << "Case " << n_test << ": ";
        s0 = "0", s1 = "1";
        // c0 = count(s0, p);
        // c1 = count(s1, p);
        if (p == "0")
        {
            cout << f(n, 1, 0) << endl;
            continue;
        }
        else if (p == "1")
        {
            cout << f(n, 0, 1) << endl;
            continue;
        }
        int idx = 2;
        for (; idx <= n; idx++)
        {
            // cout << "index" << idx << endl;

            tmp = s1;
            s1 = s1 + s0;
            s0 = tmp;
            // cout << "************\nS";
            // cout << idx << " = " << s1 << endl;
            c = cnt(s1, p);
            // if (c > 0)
            //     break;
        }
        // s0, s1 = idx-1, idx
        cout << c << endl;
        // cout << endl << c << " " << idx << endl;
        // if ((idx == n) && (c == 0))
        // {
        //     cout << 0;
        //     continue;
        // }

        // cout << f(n - idx + 1, 0, c);
        // string s = "10110";
        // cout << s.substr(3,4);
        // cout << "\nCorrect answer: "  << cnt(s, p);
    }
}
