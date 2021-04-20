#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int brokenCalc(int X, int Y)
    {

        int res = 0;
        while (Y > X)
        {
            if (Y % 2)
                Y++;
            else
                Y /= 2;
            res++;
        }
        return res + X - Y;

        // int res = 0, upper = Y;
        // if (X > Y)
        //     return X - Y;
        // int k = 0;
        // while (upper > X)
        // {
        //     k++;
        //     upper = ceil(upper / 2.);
        //     cout << "upper " << upper << endl;
        // }
        // if ((X - upper + 1) < (2 * upper - X))
        // {

        //     res = X - upper + k;
        //     X = upper * pow(2, k);
        //     cout <<"this\n";
        //     cout << X << " " << res << endl;
        // }
        // else
        // {

        //     res = upper*2 - X + k - 1;
        //     X = upper * pow(2, k);
        //     cout << "that\n";
        // }
        // // while (X < Y)
        // // {
        // // }
        // return res + X - Y;
    }
};