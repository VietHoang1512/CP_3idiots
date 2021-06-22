#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    int numberOfRounds(string startTime, string finishTime)
    {
        int hs = stoi(startTime.substr(0, 2)), ss = stoi(startTime.substr(3, 2));
        int hf = stoi(finishTime.substr(0, 2)), sf = stoi(finishTime.substr(3, 2));

        int h_diff = (hf - hs + 24) % 24;
        if (hf == hs && sf < ss)
            h_diff = 24;
        int res = 0;
        sf = sf-(sf%15);
        ss  =(ss+14) - (ss+14)%15;
        if (sf > ss)
        {
            for (int i = ss; i <= sf; i++)
            {
                if (i % 15 == 0)
                    res++;
            }
            res = max(res - 1, 0);
        }

        else
        {
            h_diff--;
            sf += 60;
            for (int i = ss; i <= sf; i++)
            {
                if (i % 15 == 0)
                    res++;
            }
            res = max(res - 1, 0);
        }

        cout << hs << ":" << ss << "->" << hf << ":" << sf << endl;
        cout << h_diff << " " << res << endl;
        return 4 * h_diff + res;
    }
};