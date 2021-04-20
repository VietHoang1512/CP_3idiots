#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int s[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date)
    {

        string year_str = date.substr(0, 4);
        string month_str = date.substr(5, 2);
        string day_str = date.substr(8, 2);
        int year = (year_str[0] - '0') * 1000 + (year_str[1] - '0') * 100 + (year_str[2] - '0') * 10 + (year_str[3] - '0');
        int month = (month_str[0] - '0') * 10 + (month_str[1] - '0');
        int day = (day_str[0] - '0') * 10 + (day_str[1] - '0');

        cout << year << " " << month << " " << day;
        if ((year % 100) && (!(year % 4)))
            s[2] = 29;
        int res = day;
        for (int i = 0; i < month; i++)
        {
            res += s[i];
        }
        return res;
    }
};