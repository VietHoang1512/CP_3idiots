class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> x{a, b, c};
        sort(x.begin(), x.end());
        a = x[0], b = x[1], c = x[2];
        if (a + b <= c)
            return b + min(a, c - b);
        int tmp = (a + b - c) / 2;
        a -= tmp, b -= tmp;
        return tmp + b + min(a, c - b);
    }
};