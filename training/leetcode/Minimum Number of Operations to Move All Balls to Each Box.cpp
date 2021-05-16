#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int total = boxes.size();
        vector<int> result(total, 0);
        for (int i = 0; i < total; i++)
        {
            int res = 0;
            for (int j = 0; j < i; j++)
            {
                if (boxes[j] == '1')
                {
                    res += (i - j);
                }
            }
            for (int j = total - 1; j > i; j--)
            {
                if (boxes[j] == '1')
                {
                    res += (j - i);
                }
            }
            result[i] = res;
        }
        return result;
    }
};