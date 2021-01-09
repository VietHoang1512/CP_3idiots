#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    int *a = new int[2 * n + 2];
    for (int i = 0; i < (2 * n + 2); i++)
    {
        a[i] = 0;
    }
    int key = n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        a[key] += 1;
        if (s[i] == '1')
        {
            key -= 1;
        }
        else
        {
            key += 1;
        }
        res += a[key];
    }
    cout << res;
    return 0;
}