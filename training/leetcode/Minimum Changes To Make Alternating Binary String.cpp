class Solution
{
public:
    int minOperations(string a)
    {
        int len = a.size();
        int odd0 = 0, odd1 = 0, even0 = 0, even1 = 0;
        for (int i = 0; i < len; i++)
        {
            if (i % 2)
            {
                if ((a[i] - '0') % 2)
                {
                    odd1++;
                }
                else
                    odd0++;
            }
            else
            {
                if ((a[i] - '0') % 2)
                {
                    even1++;
                }
                else
                    even0++;
            }
        }
        return min(odd1 + even0, odd0 + even1);
    }
};