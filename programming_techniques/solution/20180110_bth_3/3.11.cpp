#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

const int N = 200;

int n, r;
long long a[N][N];
string s;
int start_point, end_point, cur_point;
int list[N];
bool visited[N];
int b[N];
int list_size;
long long sum, res;

void func(int k)
{
    if (k == list_size)
    {
        if (a[b[k - 1]][end_point] != 0)
        {
            res = min(res, sum + a[b[k - 1]][end_point]);
        }
        return;
    }

    int x;
    for (int i = 1; i < list_size; i++)
    {
        x = list[i];
        if (visited[x] || (a[b[k - 1]][x] == 0))
        {
            continue;
        }

        else
        {
            b[k] = x;
            visited[x] = true;
            sum = sum + a[b[k - 1]][x];
            func(k + 1);
            sum = sum - a[b[k - 1]][x];
            visited[x] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin.ignore();
    while (r--)
    {
        getline(cin, s);
        s = s + " ";
        int k = 0;
        list_size = 0;
        int length_s = (int)s.length();
        for (int i = 0; i < length_s; i++)
        {
            if (s[i] == ' ')
            {
                if (k != 0)
                {
                    list[list_size] = k;
                    list_size = list_size + 1;
                }
                k = 0;
            }
            else
            {
                k = k * 10 + s[i] - '0';
            }
        }
        end_point = list[list_size - 1];
        sum = 0LL;
        res = LLONG_MAX;
        b[0] = list[0];
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }
        visited[b[0]] = true;

        func(1);
        if (res == LLONG_MAX)
        {
            res = 0;
        }
        cout << res << endl;
    }
    return 0;
}