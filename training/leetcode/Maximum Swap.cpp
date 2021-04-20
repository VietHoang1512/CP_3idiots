#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maximumSwap(int num)
    {
        int len = floor(log10(num + 0.0)) + 1;
        vector<int> digits(len, 0);
        vector<pair<int, int>> maxByIndex(len, {0, 0});
        int tmp = num;
        for (int i = 0; i < len; i++)
        {
            digits[len - 1 - i] = tmp % 10;
            tmp /= 10;
            maxByIndex[len - 1 - i] = {digits[len - 1 - i], len - 1 - i};
        }

        for (int i = len - 2; i >= 0; i--)
        {
            if (maxByIndex[i].first <= maxByIndex[i + 1].first)
            {
                maxByIndex[i] = maxByIndex[i + 1];
            }
        }
        for (int i = 0; i + 1 < len; i++)
        {
            if (digits[i] < maxByIndex[i].first)
            {

                digits[maxByIndex[i].second] = digits[i];
                digits[i] = maxByIndex[i].first;
                break;
            }
        }
        int res = 0;
        for(int i=0; i<len; i++){
            res += pow(10, i)*digits[len-1-i];
        }
        return res;
    }
};