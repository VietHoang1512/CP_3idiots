#include <iostream>

using namespace std;

int T, N, H, S;
int a[20];

void func(int k)
{
    if (k == (N + 1))
    {
        for (int i = 1; i <= N; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    int old_S = S;
    if (N - k + 1 + S < H)
    {
        return;
    }
    else if (N - k + 1 + S == H)
    {
        a[k] = 1;
        S = S + 1;
        func(k + 1);
        S = old_S;
    }
    else if (S == H)
    {
        a[k] = 0;
        func(k + 1);
    }
    else
    {
        a[k] = 0;
        func(k + 1);

        a[k] = 1;
        S = S + 1;
        func(k + 1);
        S = old_S;
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> H;
        S = 0;
        func(1);
        cout << endl;
    }
    return 0;
}