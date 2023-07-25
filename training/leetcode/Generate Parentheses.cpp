#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        cout << "\n***\n";
        for (int i = 0; i < pow(2, n * 2); i++)
        {
            if (__builtin_popcount(i) != n)
                continue;
            stack<int> s;
            int cur = i;
            bool acceptable = true;
            while (cur)
            {
                if (cur % 2 == 0)
                {
                    if (!s.empty())
                    {
                        if (s.top() != 0)
                        {
                            acceptable = false;
                            break;
                        }
                        else
                            s.pop();
                    }
                    else
                    {
                        acceptable = false;
                        break;
                    }
                    cur>>1;
                }
                else
                    s.push(1);
            }
            if (acceptable){
                cur = i;
                string s;
                while(cur){
                    if(cur%2==1) s += "(";
                    else s += ")";
                    cur >>1;
                }
                while(s.size()<2*n){
                    s += ")";    
                }
                res.push_back(s);
            }
            
            // cout << i << " " << __builtin_popcount(i) << " " << __builtin_popcount(~i) << endl;

        }
        return res;
    }
};