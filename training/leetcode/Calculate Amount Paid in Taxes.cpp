#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double res = 0;
        int i = 0, prev=0;
        while (income > 0)
        {
            cout << 0.01 * brackets[i][1] * min(income, brackets[i][0]-prev) << endl;
            res += 0.01 * brackets[i][1] * min(income, brackets[i][0]-prev);

            income -= (brackets[i][0]-prev);
            prev = brackets[i][0];
            i++;
           
        }
        cout <<"***\n";
        return res;
    }
};
