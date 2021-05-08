#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string s = to_string(N);
        int found = s.size();
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] < s[i - 1])
            {
                s[i - 1] = s[i - 1] - 1;
                found = i;
            }
        }
        for (int i = found; i < s.size(); i++)
        {
            s[i] = '9';
        }
        return stoi(s);
        //     vector<int> digits;
        //     while (N)
        //     {
        //         digits.push_back(N % 10);
        //         N /= 10;
        //     }
        //     int total = digits.size();
        //     reverse(digits.begin(), digits.end());
        //     vector<int> mn(total);
        //     int tmp = digits.back();
        //     for (int i = total - 1; i >= 0; i--)
        //     {
        //         mn[i] = tmp = min(digits[i], tmp);
        //     }
        //     vector<int> res(total, 0);

        //     int found = -1;
        //     for (int i = 0; i < total - 1; i++)
        //     {
        //         if ((digits[i] > digits[i + 1]) && ((i == 0) ||((digits[i]>digits[i-1])&&(digits[i] <= digits[i - 1] + 1))))
        //         {
        //             found = i;
        //             break;

        //         }
        //     }
        //     if (found >= 0)
        //     {
        //         for (int i = 0; i < found; i++)
        //         {
        //             res[i] = digits[i];
        //         }
        //         res[found] = digits[found] - 1;
        //         for (int i = found + 1; i < total; i++)
        //         {
        //             res[i] = 9;
        //         }
        //         tmp = 0;
        //         for (auto x : res)
        //         {
        //             cout << x << " ";
        //         }
        //         for (int i = total - 1; i >= 0; i--)
        //         {
        //             tmp += res[i] * pow(10, total - i - 1);
        //         }
        //         return tmp;
        //     }

        //     // found = -1;
        //     // for (int i = total - 1; i > 0; i--)
        //     // {
        //     //     if ((digits[i] > mn[i]) && (digits[i] > digits[i - 1]))
        //     //     {
        //     //         found = i;
        //     //         break;
        //     //     }
        //     // }
        //     // if (found >= 0)
        //     // {
        //     //     for (int i = 0; i < found; i++)
        //     //     {
        //     //         res[i] = digits[i];
        //     //     }
        //     //     res[found] = digits[found] - 1;
        //     //     for (int i = found + 1; i < total; i++)
        //     //     {
        //     //         res[i] = 9;
        //     //     }
        //     //     tmp = 0;
        //     //     for (auto x : res)
        //     //     {
        //     //         cout << x << " ";
        //     //     }
        //     //     for (int i = total - 1; i >= 0; i--)
        //     //     {
        //     //         tmp += res[i] * pow(10, total - i - 1);
        //     //     }
        //     //     return tmp;
        //     // }
        //     for (int i = 0; i < total; i++)
        //     {
        //         if (mn[i] == digits[i])
        //         {
        //             res[i] = mn[i];
        //         }
        //         else
        //         {
        //             res[i] = digits[i] - 1;
        //             for (int j = i + 1; j < total; j++)
        //             {
        //                 res[j] = 9;
        //             }
        //             break;
        //         }
        //     }
        //     tmp = 0;
        //     for (auto x : res)
        //     {
        //         cout << x << " ";
        //     }
        //     for (int i = total - 1; i >= 0; i--)
        //     {
        //         tmp += res[i] * pow(10, total - i - 1);
        //     }
        //     return tmp;
    }
};