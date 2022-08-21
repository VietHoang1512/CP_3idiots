#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int N = grid.size();
        vector<vector<int>> res(N - 2, vector<int>(N - 2, 0));
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 0; j < N - 2; j++){
                int tmp=1;
                for(int p=-1; p<=1; p++){
                    for(int q=-1; q<=1; q++){
                        if(i+1+p>=0 && i+1+p<N && j+1+q>=0 && j+1+q<N){
                            tmp = max(tmp, grid[i+1+p][j+1+q]);
                        }
                        
                    }
                }
                res[i][j] = tmp;
            }
        }
        return res;
    }
};