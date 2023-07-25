#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;
        if (money < children + 7)
            return 0;
        int res = 0;
        while ((money >= (children + 7)) && (children > 0))
        {
            money -= 8;
            children--;
            res++;
            if (children == 1)
                if (money == 4)
                    return res - 1;
                else if (money == 8)
                    return res += 1;
                else
                    return res;
        }

        return res;
    }
};