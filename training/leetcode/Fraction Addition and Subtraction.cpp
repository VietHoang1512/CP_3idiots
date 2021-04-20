#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    string fractionAddition(string expression)
    {
        vector<int> v;

        if (expression[0] != '-')
        {
            expression = "+" + expression;
        }
        int total = expression.size(), n_terms = 0;
        cout << total << endl;
        for (int i = 0; i < total; i++)
        {
            if ((expression[i] == '+') || (expression[i] == '-'))
            {
                v.push_back(i);
                n_terms++;
            }
        }
        v.push_back(total);
        pair<int, int> res = make_pair(0, 1);

        for (int i = 0; i < n_terms; i++)
        {
            int numerator = 0, denominator = 0;
            int k;
            for (int j = v[i]; j < v[i + 1]; j++)
            {
                if (expression[j] == '/')
                    k = j;
            }
            for (int j = k - 1; j > v[i]; j--)
            {
                numerator += pow(10, k - j - 1) * (expression[j] - '0');
            }
            for (int j = k + 1; j < v[i + 1]; j++)
            {
                cout << "j" << j << endl;
                denominator += pow(10, v[i + 1] - j - 1) * (expression[j] - '0');
            }
            if (expression[v[i]] == '-')
                numerator = -numerator;
            cout << "Adding " << numerator << " " << denominator << endl;
            res = myAdd(res, make_pair(numerator, denominator));
        }
        int tmp = __gcd(res.first, res.second);
        res.first /= tmp;
        res.second /= tmp;
        if (res.second < 0)
        {
            res.first = -res.first;
            res.second = -res.second;
        }
        return to_string(res.first) + "/" + to_string(res.second);
    }

    pair<int, int> myAdd(pair<int, int> A, pair<int, int> B)
    {
        return make_pair(A.first * B.second + B.first * A.second, A.second * B.second);
    }
};