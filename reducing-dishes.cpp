class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int len = satisfaction.size();
        int sum[500], dp[500], tmp = 0;

        sort(satisfaction.begin(), satisfaction.end());

        for (int i = 0; i < len; i++)
        {
            tmp += satisfaction[len - i - 1];
            sum[len - i - 1] = tmp;
        }
        cout << "satisfaction\n";
        for (int i = 0; i < len; i++)
        {
            cout << satisfaction[i] << " ";
        }

        cout << "\nsum\n";
        for (int i = 0; i < len; i++)
        {
            cout << sum[i] << " ";
        }

        dp[0] = 0;
        for (int i = 0; i < len; i++)
        {
            dp[0] += (i + 1) * satisfaction[i];
        }
        cout << "\ndp\n"
             << dp[0] << " ";
        tmp = dp[0];
        for (int i = 1; i < len; i++)
        {
            dp[i] = dp[i - 1] - sum[i - 1];
            cout << dp[i] << " ";
            tmp = max(tmp, dp[i]);
        }
        tmp = max(0, tmp);

        return tmp;
    }
};