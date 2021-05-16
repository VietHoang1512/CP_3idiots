#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        return (coordinates[0] - 'a' + coordinates[1] - '1') % 2;
    }
};