#include <bits/stdc++.h>

using namespace std;

long long W, c;
//                      0, 1, 2, 3, 4, 5, 6, 7, 8, 9
long long number[10] = {0, 1, 1, 1, 2, 1, 2, 1, 1, 3};
long long count_[10] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
int main()
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        // cout << "****************\n";
        cin >> W >> c;
        long long cnt = 0, num = 1;
        long long high = 5 * pow(10, c + 3);
        if ((W % 1000) || (W > high))
        {
            cout << 0 << endl;
            continue;
        }
        while (W)
        {
            if (!(W % 10))
            {
                W /= 10;
                continue;
            }
            long long tmp = (W % 10);
            cnt += count_[tmp];
            num *= number[tmp];
            W /= 10;
        }
        cout << cnt << " " << num << endl;
    }
}