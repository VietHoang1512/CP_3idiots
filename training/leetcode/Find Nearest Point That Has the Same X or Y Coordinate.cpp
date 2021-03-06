#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int res = INT_MAX, result=0, total=points.size();
        for (int i=0; i<total; i++)
        {
            if ((points[i][0] == x) || (points[i][1] == y))
            {
                if(res>abs(points[i][0] - x) + abs(points[i][1] - y)){
                    res = abs(points[i][0] - x) + abs(points[i][1] - y);
                    result=i;
                }
                
            }
        }
        return (res==INT_MAX)?-1:result;
    }
};