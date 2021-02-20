class Solution
{
public:
    int totalMoney(int n)
    {
        int tmp = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i > 0) && (!(i % 7)))
                tmp -= 5;
            else
                tmp++;
            res += tmp;
        }
        return res;
    }
};