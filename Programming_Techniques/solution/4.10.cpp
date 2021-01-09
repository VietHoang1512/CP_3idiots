#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

const int N = 1001;
int n, q;
string s, t = "";
map<string, int> f[N];
int maxf[N];
map<string, int> df;
double diemso[N][N];

double tinhdiem(string t, int d)
{
    if (!df.count(t))
    {
        return 0;
    }
    if (!f[d].count(t))
    {
        return 0;
    }
    double tf = 0.5 + 0.5 * f[d][t] / maxf[d];
    double idf = log(n * 1.0 / df[t]) / log(2);
    return (double)tf * idf;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int dodai;
    for (int i = 1; i <= n; i++)
    {
        maxf[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        s += ',';
        dodai = (int)s.length();
        for (int k = 0; k < dodai; k++)
        {
            if (s[k] == ' ')
            {
                continue;
            }
            if (s[k] == ',')
            {
                if (t == "")
                {
                    continue;
                }
                if (f[i].count(t))
                {
                    f[i][t] += 1;
                }
                else
                {
                    f[i].insert(make_pair(t, 1));

                    if (df.count(t))
                    {
                        df[t] += 1;
                    }
                    else
                    {
                        df.insert(make_pair(t, 1));
                    }
                }

                maxf[i] = max(maxf[i], f[i][t]);
                t = "";
            }
            else
            {
                t += s[k];
            }
        }
    }

    cin >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            diemso[i][j] = 0;
        }
    }

    for (int j = 1; j <= q; j++)
    {
        cin >> s;
        s += ',';
        dodai = (int)s.length();
        for (int k = 0; k < dodai; k++)
        {
            if (s[k] == ' ')
            {
                continue;
            }
            if (s[k] == ',')
            {
                if (t == "")
                {
                    continue;
                }
                for (int i = 1; i <= n; i++)
                {
                    diemso[i][j] += tinhdiem(t, i);
                }
                t = "";
            }
            else
            {
                t += s[k];
            }
        }
    }

    int chon;
    for (int j = 1; j <= q; j++)
    {
        chon = 1;
        for (int i = 2; i <= n; i++)
        {
            if (diemso[i][j] > diemso[chon][j])
            {
                chon = i;
            }
        }
        cout << chon << endl;
    }

    // for (int j = 1; j <= q; j++)
    // {
    //     cout << "Truy vấn " << j << " : ";
    //     for (int i = 1; i <= n; i++)
    //     {
    //         cout << diemso[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << maxf[i] << endl;
    // }

    // for (auto x : df)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    return 0;
}