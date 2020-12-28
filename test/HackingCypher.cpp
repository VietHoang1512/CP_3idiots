#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

const int mx = 1000000;
char s[mx];
int a, b, tmp;
int A[mx], B[mx], C[mx];

int main()
{
    cin >> s >> a >> b;

    int len = strlen(s);

    // init
    A[0] = (s[0] - '0') % a;
    B[len - 1] = (s[len - 1] - '0') % b;

    //cout << A[0] << " ";
    for (int i = 1; i < len; i++)
    {
        tmp = s[i] - '0';
        A[i] = ((10 * A[i - 1]) + tmp) % a;
        //cout << A[i]<< " ";
    }
    //cout << endl;
    C[0] = 1;
    for (int i = 1; i < len; i++)
    {
        C[i] = (10 * C[i - 1]) % b;
    }

    for (int i = len - 2; i >= 0; i--)
    {
        tmp = s[i] - '0';
        B[i] = (B[i + 1] + C[len - 1 - i] * tmp) % b;
    }

    for (int i = 0; i < len; i++)
    {
        //cout << B[i] << " ";
    }

    //cout << "\n\n\n";
    bool non = true;

    for (int i = 0; i < len - 1; i++)
    {
        if (s[i + 1] == '0')
            continue;
        if ((A[i] == 0) && (B[i] == 0))
        {
            cout << "YES\n";
            non = false;
            for (int j = 0; j <= i; j++)
            {
                cout << s[j];
            }
            cout << endl;
            for (int j = i + 1; j < len; j++)
            {
                cout << s[j];
            }
        }
    }
}