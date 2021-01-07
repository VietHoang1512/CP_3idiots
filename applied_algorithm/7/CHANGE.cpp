#include <bits/stdc++.h>

using namespace std;

int N;
int currency[] = {1, 5, 10, 50, 100, 500};

int main()
{
    cin >> N;
    int total = 1000 - N;
    int cur_id = 5;
    int cnt = 0;
    while (total)
    {
        if (total >= currency[cur_id])
        {
            cnt += (total / currency[cur_id]);
            total %= currency[cur_id];
        }
        else
            cur_id--;
    }
    cout << cnt;
}