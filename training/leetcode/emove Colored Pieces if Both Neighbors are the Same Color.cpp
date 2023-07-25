#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.size();
        int cntA=0, cntB=0, A=0, B=0;
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == 'A'){
                cntA++;
                cntB=0;
                if(cntA>=3) A++;
            }else{
                cntB++;
                cntA=0;
                if(cntB>=3) B++;
            }
        }
        if (A>B) return true;
        return false;
    }
};