#include <bits/stdc++.h>

using namespace std;
float a, b, z;
int main()
{
    cin >> a >> b;
    z = sqrt(a * a + b * b);
    cout << fixed;
    cout << setprecision(2);
    cout << "z = " << z;
}