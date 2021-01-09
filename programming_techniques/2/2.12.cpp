#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dict;

int main()
{
    int key, value;

    while (cin >> key)
    {
        cin >> value;
        dict.push_back(pair<int, int>(key, value));
    }

    sort(dict.begin(), dict.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool {
        if (p1.second == p2.second)
        {
            return (p1.first > p2.first);
        }
        return p1.second >= p2.second;
    });

    for (auto e : dict)
    {
        cout << e.first << " " << e.second << endl;
    }
}
