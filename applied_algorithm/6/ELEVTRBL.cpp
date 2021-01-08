#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6 + 5;

int F, S, G, U, D;
int visited[mx], cost=INT_MAX, cur_cost;
bool found;

void TRY(int s)
{
    // cout << "Go to " << s << endl;
    if (s == G)
    {
        cost = min(cost, cur_cost);
        found = true;
        return;
    }
    visited[s] = 1;
    int down = s - D, up = s + U;
    // cout << "UP " << up << " DOWN " << down << endl;
    if ((up <= F) && (!visited[up]))
    {
        cur_cost++;

        TRY(up);
        // cout << "Back to " << s << endl;
        cur_cost--;
    }
    if ((down > 0) && (!visited[down]))
    {
        cur_cost++;
        TRY(down);
        // cout << "Back to " << s << endl;
        cur_cost--;
    }
}

int main()
{
    cin >> F >> S >> G >> U >> D;
    TRY(S);
    if (found)
    {
        cout << cost;
    }
    else
    {
        cout << "use the stairs";
    }
}