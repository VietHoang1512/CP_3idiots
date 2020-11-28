#include <bits/stdc++.h>

using namespace std;
int N;

int main()
{
    cin >> N;
    int cnt = 0;
    for (int i = 1; i < 10; i++)
        for (int c = 1; c < 10; c++)
            for (int t = 1; t < 10; t++)
                for (int h = 1; h < 10; h++)
                    for (int u = 1; u < 10; u++)
                        for (int s = 1; s < 10; s++)
                            for (int k = 1; k < 10; k++)
                            {
                                if ((100 * i + 10 * c + t - 100 * k - 62 + h * 1000 + u * 100 + s * 10 + t) == N)
                                {
                                    set<int> x;
                                    x.insert(i);
                                    x.insert(c);
                                    x.insert(t);
                                    x.insert(h);
                                    x.insert(u);
                                    x.insert(s);
                                    x.insert(k);
                                    if (x.size() == 7)
                                        cnt++;
                                }
                            }
    cout << cnt;
}