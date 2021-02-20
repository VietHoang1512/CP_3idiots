class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int len = nums.size(), res = 0;
        int val[500000];
        sort(nums.begin(), nums.end());
        map<int, int> m;
        for (auto x : nums)
        {
            val[x] = 1;
        }
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len ; j++)
            {
                int tmp = nums[i]*nums[j];
                if(! m.count(tmp)){
                    m.insert(pair<int, int>(tmp,1));
                }else m[tmp]++;
                    
            }
        }
        for (auto x: m){
            // if(x.second>1){
                res += 4*(x.second-1)*x.second;
                // cout << x.first << " " << x.second << endl;
            // }
                
        }
        return res;
    }
};