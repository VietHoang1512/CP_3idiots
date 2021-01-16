#include <bits/stdc++.h>

using namespace std;

const long long mx = 1e6 + 5;
long long n, a, A[mx];
long long left_incr[mx], left_decr[mx], right_incr[mx], right_decr[mx];
long long incr, decr, tmp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (long long i = 2; i <= n; i++)
    {
        if (A[i] > A[i - 1])
            left_incr[i] = left_incr[i - 1] + 1;
        else if (A[i] < A[i - 1])
            left_decr[i] = left_decr[i - 1] + 1;
    }
    // cout << "Left increase\n";
    // for(long long i=1; i<=n; i++){
    //     cout << left_incr[i] << " ";
    // }
    // cout << endl;

    // cout << "Left decrease\n";
    // for(long long i=1; i<=n; i++){
    //     cout << left_decr[i] << " ";
    // }
    // cout << endl;

    // cout << "Right increase\n";
    // for(long long i=1; i<=n; i++){
    //     cout << right_incr[i] << " ";
    // }
    // cout << endl;

    // cout << "Right decrease\n";
    // for(long long i=1; i<=n; i++){
    //     cout << right_decr[i] << " ";
    // }
    // cout << endl;

    for (long long i = n - 1; i >= 1; i--)
    {
        if (A[i] > A[i + 1])
            right_incr[i] = right_incr[i + 1] + 1;
        else if (A[i] < A[i + 1])
            right_decr[i] = right_decr[i + 1] + 1;
    }
    cout << endl;

    for (long long i = 1; i <= n; i++)
    {
        // cout << tmp << " ";
        tmp = min(left_incr[i], right_incr[i]);
        incr = max(incr, tmp);
        // cout << tmp << " ";
        tmp = min(left_decr[i], right_decr[i]);
        decr = max(decr, tmp);
        // cout << " | "   ;
    }
    // cout << endl;

    cout << incr << " " << decr;
}


