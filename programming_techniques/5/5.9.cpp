#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while (n--)
    {
        int k, t;
        cin >> k >> t;
        int a;
        cin >> a;
        sum += k * t * a;
        ans = max(ans, -sum);
        // while(k--){
        //     int a;
        //     cin >> a;
        //     if (t == 1) sum += a;
        //     if (t == -1) sum -= a;
        //     ans = max(ans, -sum);
        // }
    }
    cout << ans;
}