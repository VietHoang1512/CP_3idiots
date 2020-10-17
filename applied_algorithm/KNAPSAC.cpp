#include <bits/stdc++.h>
using namespace std;

int n, b;
int ai, ci;
vector<pair<int, int>> v;

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> ai >> ci;
        v.push_back(pair<int, int>(ai, ci));
    }
    cout << "DONE";
}