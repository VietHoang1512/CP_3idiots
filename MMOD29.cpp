#include <iostream>
#include <cmath>
using namespace std;

long long f(int x)
{
    long TuSo = (pow(2, 2 * x + 1) - 1) * (pow(3, x + 1) - 1) * (pow(-7, x + 1) - 1);
    int MauSo = 2 * (-8);
    long tmp = long(TuSo / MauSo) % 29;
    if (tmp > 0)
        return tmp;
    return tmp + 29;
}

int main()
{
    //string s;
    //cin >> s;
    //cout << s;
    long long x;
    while (cin >> x)
    {
        if (x == 0)
            break;
        x %= 28;
        cout << f(x) << endl;
    }
}