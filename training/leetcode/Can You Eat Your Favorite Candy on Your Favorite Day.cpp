class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<bool> res;
        int total = queries.size();

        for (int i = 0; i < total; i++)
        {
            // cout << "*************\n";

            vector<unsigned long long> cnt;
            for (auto x : candiesCount)
                cnt.push_back(x);

            // vector<unsigned long long> query = queries[i];
            unsigned long long min_day = 1, max_day = 0;

            unsigned long long type = queries[i][0];
            unsigned long long day = queries[i][1];
            unsigned long long max_candy = queries[i][2];


            for (int j = 0; j <= type; j++)
            {
                max_day += cnt[j];
            }

            for (int k = 0; k < type; k++)
            {
                min_day += (cnt[k] / max_candy);
                cnt[k] = (cnt[k] % max_candy);
                min_day += (cnt[k] > 0);
            }

            cout << min_day << " " << max_day << endl;
            res.push_back((min_day <= day) && (max_day >= day));
        }

        return res;
    }
};