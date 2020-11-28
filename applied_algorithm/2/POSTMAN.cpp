#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long cur_pos = 0, cost = 0, cur, tmp;

vector<pair<long long, long long>> v;
pair<long long, long long> p;
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first < b.first;
}

int main()
{
    cin >> n >> k;
    cur = 0;
    for (long long i = 0; i < n; i++)
    {
        pair<long long, long long> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        p = v[i];
        if (p.first > 0){
            break;
        }
            
        // cost += abs(cur_pos - p.first);
        // cur_pos = p.first;
        // cout << "\nOn position " << p.first << " requires " << p.second << " units\n\n";
        // cout << "start current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        // tmp = min(cur, p.second);
        // cur -= tmp;
        // p.second -= tmp;
        // cout << "first current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        if (cur > p.second)
        {
            cur -= p.second;
        }
        else
        {
            p.second -= cur;
            cur = 0;
            tmp = p.second / k;
            cost += -2 * tmp * p.first;
            p.second = p.second % k;

            if (p.second > 0)
            {
                cur += k;
                cost += -2 * p.first;
                cur -= p.second;
                p.second = 0;
            }
        }
        // cout << "second current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        // cout << "end current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;
    }

    cur = 0;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        p = v[i];
        if (p.first < 0){
            break;
        }
        // cost += abs(cur_pos - p.first);
        // cur_pos = p.first;
        // cout << "\nOn position " << p.first << " requires " << p.second << " units\n\n";
        // cout << "start current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        // tmp = min(cur, p.second);
        // cur -= tmp;
        // p.second -= tmp;
        // cout << "first current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        if (cur > p.second)
        {
            cur -= p.second;
        }
        else
        {
            p.second -= cur;
            cur = 0;
            tmp = p.second / k;
            cost += 2 * tmp * p.first;
            p.second = p.second % k;

            if (p.second > 0)
            {
                cur += k;
                cost += 2 * p.first;
                cur -= p.second;
                p.second = 0;
            }
        }
        // cout << "second current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;

        // cout << "end current unit " << cur << " current cost " << cost << " still requires " << p.second << endl;
    }

    cout << cost;
}