#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool found = false;
    while (n--)
    {
        int a;
        cin >> a;
        if (!(a % 400))
        {
            found = true;
            break;
        }
        else if (!(a % 100))
        {
            continue;
        }
        else if (!(a % 4))
        {
            found = true;
            break;
        }
        // if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
        // {
        //     cout << "Yes";
        //     return 0;
        // }
    }
    if (found) cout << "Yes";
    else
    cout << "No";
}