#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int total = arr.size();

    }
    
    int countElements(vector<int> &arr, int x, int range){
        int cnt;
        for(auto e: arr){
            if(abs(e-x)<=range) cnt++;
        }
        return cnt;
    }
};