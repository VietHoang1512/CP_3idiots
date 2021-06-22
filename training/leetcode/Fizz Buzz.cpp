#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        if (n == 1)
            return {"1"};
        vector<string> v = fizzBuzz(n - 1);
        if (n % 15 == 0)
        {
            v.push_back("FizzBuzz");
        }
        else if (n % 3 == 0)
        {
            v.push_back("Fizz");
        }
        else if (n % 5 == 0)
        {
            v.push_back("Buzz");
        }
        else
        {
            v.push_back(to_string(n));
        }
        return v;
    }
};