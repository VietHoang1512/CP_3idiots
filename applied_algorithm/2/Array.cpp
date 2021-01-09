#include <bits/stdc++.h>

using namespace std;

vector<int> pos, neg, zeros;
int N, tmp, n_zeros;
int n_pos, n_neg;
int main()
{
    cin >> N;
    while (N--)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            pos.push_back(tmp);
        }
        else if (tmp < 0)
        {
            neg.push_back(tmp);
        }
        else
        {
            zeros.push_back(0);
        }
    }

    n_pos = pos.size(), n_neg = neg.size();

    if (n_pos == 0)
    {
        pos.push_back(neg[n_neg - 1]);
        pos.push_back(neg[n_neg - 2]);
        neg.pop_back();
        neg.pop_back();
    }

    n_pos = pos.size(), n_neg = neg.size();

    if (!(n_neg % 2))
    {
        zeros.push_back(neg[n_neg - 1]);
        neg.pop_back();
    }

    cout << neg.size() << " ";

    for (auto x : neg)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << pos.size() << " ";

    for (auto x : pos)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << zeros.size() << " ";
    for (auto x : zeros)
    {
        cout << x << " ";
    }
}