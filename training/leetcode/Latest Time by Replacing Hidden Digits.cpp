class Solution
{
public:
    string maximumTime(string time)
    {
        string res = "";
        for (int i = 0; i < 5; i++)
        {
            if (time[i] == '?')
            {
                // cout << i;
                if (i == 0)
                {
                    if ((time[1] != '?') && (time[1] - '0' > 3))
                        res += "1";
                    else
                        res += "2";
                }
                else if (i == 1)
                {
                    if (res[0] == '2')
                        res += "3";
                    else
                        res += "9";
                }
                else if (i == 3)
                {
                    res += "5";
                }
                else
                {
                    res += "9";
                }
            }
            else
            {
                res += time[i];
            }
        }
        return res;
    }
};