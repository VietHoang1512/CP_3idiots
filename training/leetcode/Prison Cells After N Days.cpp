#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        map<vector<int>, int> m;
        map<int, vector<int>> d;

        vector<int> new_cells;
        new_cells.insert(new_cells.begin(),cells.begin(), cells.end());
        m[cells] = 0;
        d[0] = cells;
        int s_period, e_period;
        for (int i = 1; i <= 256; i++)
        {
            
            new_cells = next_cells(new_cells);
            // cout<< "\nDay "<< i << ": ";
            // for(auto x:new_cells)
            //     cout << x << " ";
            
            
            if (n == i)
                return new_cells;
            if (m[new_cells])
            {
                s_period = m[new_cells];
                e_period = i;
                // cout << "start: " << s_period <<" end: " << e_period;
                break;
            }
            d[i] = new_cells;
            m[new_cells]=i;
        }

        return d[(n-s_period)%(e_period-s_period)+s_period];
    }
    vector<int> next_cells(vector<int> &cells)
    {
        vector<int> new_cells(8, 0);

        for (int i = 1; i < 7; i++)
        {
            if (cells[i - 1] == cells[i + 1])
                new_cells[i] = 1;
            else
                new_cells[i] = 0;
        }
        return new_cells;
    }
};