#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

int n, len;
string s;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        len = s.length();
        if (len < 11)
        {
            cout << s << endl;
            continue;
        }
        cout << s[0];
        cout << len - 2;
        cout << s[len - 1];
        cout << endl;
    }
}