bool compare(vector<int> a, vector<int> b)
{
    if (a[1] > b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] > b[0];
    return false;
}
class Solution
{
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<vector<int>> res;
        int total = restaurants.size();
        for (int i = 0; i < total; i++)
        {
            if ((restaurants[i][2] >= veganFriendly) && (restaurants[i][3] <= maxPrice) && (restaurants[i][4] <= maxDistance))
            {
                res.push_back(restaurants[i]);
            }
        }
        sort(res.begin(), res.end(), compare);
        vector<int> tmp;
        for (auto x : res)
        {
            tmp.push_back(x[0]);
            cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
        }
        return tmp;
    }
};