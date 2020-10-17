#include <bits/stdc++.h>

using namespace std;
const int mx = 1e5;
int N, Q, res = 0, pi, ci;

int main()
{   
    cin >> N;
    vector<int> t(N + 2);
    t[0] = INT_MAX;
    t[N + 1] = INT_MAX;

    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
        if (t[i] != t[i - 1])
            res++;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> pi >> ci;
        if (t[pi] != t[pi - 1])
            res--;

        if (t[pi] != t[pi + 1])
            res--;

        if (ci != t[pi - 1])
            res++;

        if (ci != t[pi + 1])
            res++;

        t[pi] = ci;
        cout << res << endl;
    }
}
