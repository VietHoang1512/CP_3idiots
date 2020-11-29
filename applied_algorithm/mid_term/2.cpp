#include <bits/stdc++.h>
using namespace std;

long long n, p[100000];
string s;
stack<long long> C;
queue<long long> H;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (long long i = n; i >= 1; i--)
    {
        C.push(p[i]);
        // cout << p[i];
    }
    cin >> s;
    long long tmp;
    long long size = s.size();
    for (long long i = 0; i < size; i++)
    {
        if ((s[i] == 'C') && (!C.empty()))
        {
            tmp = C.top();
            C.pop();
            H.push(tmp);
        }

        else
        {
            if (!H.empty())
            {
                tmp = H.front();
                H.pop();
                C.push(tmp);
            }
        }
    }

    while (!C.empty())
    {
        cout << C.top() << " ";
        C.pop();
    }
    return 0;
}
