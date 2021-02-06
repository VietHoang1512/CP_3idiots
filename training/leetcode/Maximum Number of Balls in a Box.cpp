int sumDigit(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
class Solution
{
public:
    int dp[50];
    int countBalls(int lowLimit, int highLimit)
    {
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++)
        {
            dp[sumDigit(i)]++;
            res = max(res, dp[sumDigit(i)]);
        }
        return res;
    }
};