#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 1e5 + 5;
class SeatManager
{
public:
    int seat[mx];
    int cur, N;
    SeatManager(int n)
    {
        memset(seat, 0, sizeof(seat));
        N = n;
        cur = 1;
    }

    int reserve()
    {

        cout << "rereseving " << cur << "\nfinding new reserve ";
        seat[cur] = 1;
        int tmp = cur;
        cur++;
        for (int i = tmp; i <= N; i++)
        {
            cout << i << "-" << seat[i] << " ";
            if (seat[i] == 0)
            {
                cur = i;
                break;
            }
        }
        cout << "Found " << cur << "\n";
        return tmp;
    }

    void unreserve(int seatNumber)
    {

        seat[seatNumber] = 0;
        cur = min(cur, seatNumber);
        cout << "unreserving " << seatNumber << " current " << cur << endl;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */