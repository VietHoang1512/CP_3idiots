#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        set<int> s;
        for (auto x : sentence)
        {
            if ((x >= 'a') || (x <= 'z'))
                s.insert(x - 'a');
        }
        cout << s.size();
        return s.size() == ('z' - 'a' + 1);
    }
};