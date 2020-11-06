#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

float pi = 3.14159265358979323846;
const int mx = 10000;

int n_test, N, F, n_iter = 50;
float ri;
vector<float> r;
float res;
float low, mid, high;

bool is_divisible(float x)
{
    int n_pieces = 0;
    for (auto ri : r)
    {
        n_pieces += (int)floor(pi * ri * ri / x);
        if (n_pieces >= F + 1)
            return true;
    }

    return false;
}

bool cmp(double x, double y)
{
    return x > y;
}

int main()
{
    cin >> n_test;
    while (n_test--)
    {
        r.clear();
        low = 0, mid, high = 4e8;
        cin >> N >> F;
        for (int i = 1; i <= N; i++)
        {
            cin >> ri;
            r.push_back(ri);
        }
        sort(r.begin(), r.end(), cmp);

        // cout << high;
        for (int i = 1; i <= n_iter; i++)
        {
            mid = (high + low) / 2.0;

            if (is_divisible(mid))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << fixed << setprecision(6) << mid;
        cout << endl;
    }
}