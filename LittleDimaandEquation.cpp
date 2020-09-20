#include <bits/stdc++.h>
#include <math.h>
using namespace std;

const long long mx = 100;

int s(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long power(long long base, long long exp)
{
    long long res = 1;
    while (exp--)
    {
        res *= base;
    }
    return res;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long a, b, c;
    cin >> a >> b >> c;
    long long res[mx];
    long long x, cnt = 0;

    // TODO: improve brute force strategy
    // for (long long x=0; x<mx; x++){
    // 	if(x==(long long) (b*(pow(s(x),a))+c)){
    //     res[cnt] = x;
    //     cnt++;
    //     }else if(x<(long long) (b*(pow(s(x),a))+c)) break;
    // }

    for (int sx = 1; sx <= 81; sx++)
    {
        x = (long long)(b * (power(sx, a)) + c);
        if ((s(x) == sx) && (x < 1000000000))
        {
            res[cnt] = x;
            cnt++;
        }
    }

    cout << cnt << endl;
    for (long long i = 0; i < cnt; i++)
    {
        cout << res[i] << " ";
    }
}