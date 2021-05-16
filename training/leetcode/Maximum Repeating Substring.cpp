#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        cout << endl;
        int res = 0;
        string tmp = word;
        while (sequence.find(tmp) != string::npos)
        {
            res++;
            tmp.append(word);
        }
        return res;
    }
};