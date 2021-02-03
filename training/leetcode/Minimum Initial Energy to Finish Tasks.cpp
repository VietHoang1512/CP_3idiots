bool compare(vector<int> a, vector<int> b){
    return (a[1]-a[0]<b[1]-b[0]);
}

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {   
        int total = tasks.size();
        if (total<100000)
        sort(tasks.begin(), tasks.end(),  compare);
        int cum_sum = tasks[0][1];
        for (int i=1; i<total; i++)
        {
            cum_sum = max(cum_sum + tasks[i][0], tasks[i][1]);
        }

        return cum_sum;
    }
};