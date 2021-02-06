int f(int k)
{
    return k * (k - 1) / 2;
}
int max_not_exceed(int n, int k)
{
    int tmp = 0;
    for (int i = 1; i < k; i++)
    {
        if ((i * (i + 1) / 2) > n)
            return i;
    }
    return 0;
}
class Solution
{
public:
    int minimumBoxes(int n)
    {
        // if(n==15) return 9;
        int tmp = 0;
        for (int i = 2; i <= n; i++)
        {
            cout << i << " " << f(i) << " " << tmp << endl;
            tmp += f(i);
            if (tmp >= n)
                return f(i);
            int add = n - tmp;
            int k = max_not_exceed(add, i);
            if (k)
                return f(i) + k;
            if (tmp + i >= n)
                return f(i) + n - tmp;
        }
        return 0;
    }
};