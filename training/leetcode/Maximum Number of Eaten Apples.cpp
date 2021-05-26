#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        cout << endl;
        int total = apples.size(), res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

        for (int i = 0; i < total; i++)
        {

            PQ.push({i + days[i], apples[i]});

            while (PQ.size() && (PQ.top().first <= i))
            {
                cout << "Pop " << PQ.top().first << endl;
                PQ.pop();
            }
            if (PQ.size() && (PQ.top().first > i))
            {
                res++;
                auto tmp = PQ.top();
                cout << "Eat " << tmp.first << endl;
                tmp.second--;
                PQ.pop();
                if (tmp.second)
                    PQ.push(tmp);
            }
        }
        return res;
    }
};