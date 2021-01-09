#include <iostream>
#include <queue>

using namespace std;

struct doantuongthanh
{
    int a, k, q, r;
    bool dalaydu;
    void set_value(int _a, int _k)
    {
        a = _a;
        k = _k;
        q = a / k;
        r = a % k;
        if (r == 0)
        {
            dalaydu = true;
        }
        else
        {
            dalaydu = false;
        }
    }
};

doantuongthanh tt[100001];

int main()
{
    int n;
    long long s, solinhtoida = 0;
    long long giacxongvao = 0;
    cin >> n >> s;
    int a, k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> k;
        tt[i].set_value(a, k);
        if (tt[i].dalaydu)
        {
            PQ.push(make_pair(tt[i].k, i));
            solinhtoida += tt[i].q;
        }
        else
        {
            PQ.push(make_pair(tt[i].r, i));
            solinhtoida += tt[i].q + 1;
        }
    }

    if (solinhtoida <= s)
    {
        cout << 0;
        return 0;
    }

    while (solinhtoida > s)
    {
        int top = PQ.top().second;
        if (!tt[top].dalaydu)
        {
            solinhtoida -= 1;
            giacxongvao += tt[top].r;
            tt[top].dalaydu = true;
            PQ.pop();
            if (tt[top].q != 0)
            {
                PQ.push(make_pair(tt[top].k, top));
            }
        }
        else
        {
            if (tt[top].q < (solinhtoida - s))
            {
                solinhtoida -= tt[top].q;
                giacxongvao += tt[top].q * tt[top].k;
                PQ.pop();
            }
            else
            {
                giacxongvao += (solinhtoida - s) * tt[top].k;
                solinhtoida = s;
            }
        }
    }
    cout << giacxongvao;
    return 0;
}