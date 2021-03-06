class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int cnt = 0;
        while (n)
        {
            while (!(n % 3))
            {
                n /= 3;
            }
            if (n % 3 == 2)
                return false;
            if (n % 3 == 1)
            {
                n--;
            }
        }
        return true;
    }
};