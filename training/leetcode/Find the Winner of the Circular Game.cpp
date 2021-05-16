#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> player(n, 1);
        int cur = n - 1, pos = 0;
        while (cur--)
        {
            int next = k;
            for (int i = pos; i < pos + next; i++)
            {
                if (!player[i % n])
                {
                    next++;
                }
                if (i == pos + next - 1)
                {
                    player[i % n] = 0;
                    // cout << "Turn " << (n - cur) << " remove player " << (i % n) << endl;
                    pos = (i + 1) % n;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (player[i])
                return i + 1;
        }
        return 0;
    }
};