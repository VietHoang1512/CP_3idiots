#include <bits/stdc++.h>
using namespace std;

char cal(double a)
{
    if (a < 4)
        return 'F';
    if (4 <= a && a < 5.5)
        return 'D';
    if (5.5 <= a && a < 7)
        return 'C';
    if (7 <= a && a < 8.5)
        return 'B';
    if (8.5 <= a)
        return 'A';
}

int main()
{
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (8.5 <= a)
            ++A;
        if (7 <= a && a < 8.5)
            ++B;
        if (5.5 <= a && a < 7)
            ++C;
        if (4 <= a && a < 5.5)
            ++D;
        if (a < 4)
            ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}