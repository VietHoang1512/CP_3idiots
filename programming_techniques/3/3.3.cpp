#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr = 0;       //# tổng chi phí tới thời điểm hiện tại
int mark[MAX];      //# đánh dấu những thành phố đã đi
int x[MAX];         //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
                cmin = min(cmin, c[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k)
{
    // cout << "Visited " << k - 1 << " cost " << curr << endl;
    if (curr + (n + 2 - k) * cmin > best)
        return;

    if (k == n + 1)
    {
        // curr += ;
        best = min(best, curr+c[x[k-1]][1]);
        // cout << "accept " << curr << " cost " << curr << endl;
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            x[k] = i;
            int cost = c[x[k - 1]][x[k]];
            curr += cost;
            TRY(k + 1);
            curr -= cost;
            mark[i] = 0;
        }
    }
}

int main()
{
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}