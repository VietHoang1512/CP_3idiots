#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {
        int n = encoded.size() + 1;
        for (int i = 0; i < n - 1; i++)
        {
            cout << (encoded[i] ^ encoded[i + 1]) << " ";
        }
        cout << endl;
        vector<int> res;
        return res;
    }
};