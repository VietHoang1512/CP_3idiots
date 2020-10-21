#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return accumulate(a.begin(), a.end(), 0) > accumulate(b.begin(), b.end(), 0);
}

int main()
{
    int val1, val2;
    cin >> val1 >> val2;
    vector<vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # YOUR CODE HERE #
    *****************/
    //    for(int i=0; i<a.size(); i++){
    //        sort(a[i].begin(),a[i].end());
    //    }
    sort(a.begin(), a.end(), compare);
    for (const auto &v : a)
    {
        for (int it : v)
        {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}