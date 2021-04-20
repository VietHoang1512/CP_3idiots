#include <bits/stdc++.h>
using namespace std;

int main()
{
}
bool cmp(vector<int> &p1, vector<int> &p2)
{
    if (p1[0] > p2[0])
        return true;
    if (p1[0] == p2[0])
    {
        if (p1[1] >= p2[1])
            return true;
        else
            return false;
    }
    return false;
}

bool cmp(vector<int> &p1, vector<int> &p2)
{
    if (p1[0] > p2[0])
        return true;
    if (p1[0] == p2[0])
    {
        if (p1[1] >= p2[1])
            return true;
        else
            return false;
    }
    return false;
}
class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> v;
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        sort(v.begin(), v.end(), cmp);
        vector<int> tmp = v[3];

        v[3] = v[2];
        v[2] = tmp;
        for (auto p : v)
        {
            cout << p[0] << " " << p[1] << endl;
        }
        cout << "******************\n";
        if (distance(v[0], v[1]) == 0)
            return false;
        if ((distance(v[0], v[1]) == distance(v[1], v[2])) && (distance(v[0], v[1]) == distance(v[3], v[2])) && distance(v[0], v[1]) == distance(v[0], v[3]))
        {
            if (distance(v[0], v[2]) == distance(v[1], v[3]))
                return true;
        }
        return false;
    }
    int distance(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};