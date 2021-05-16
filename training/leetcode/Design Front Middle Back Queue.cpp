#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class FrontMiddleBackQueue
{
public:
    vector<int> v;
    int n = 0;
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        vector<int> tmp = {val};
        tmp.insert(tmp.end(), v.begin(), v.end());
        v = tmp;
        n++;
    }

    void pushMiddle(int val)
    {
        vector<int> tmp(n + 1, 0);
        int middle = n / 2;
        for (int i = 0; i < middle; i++)
        {
            tmp[i] = v[i];
        }
        tmp[middle] = val;
        for (int i = middle; i < n; i++)
        {
            tmp[i + 1] = v[i];
        }
        n++;
        v = tmp;
    }

    void pushBack(int val)
    {
        v.push_back(val);
        n++;
    }

    int popFront()
    {
        if (!n)
            return -1;
        vector<int> tmp;
        for (int i = 1; i < n; i++)
        {
            tmp.push_back(v[i]);
        }
        n--;
        int x = v[0];
        v = tmp;
        return x;
    }

    int popMiddle()
    {
        if (!n)
            return -1;
        int middle = (n - 1) / 2;
        int x = v[middle];
        vector<int> tmp(n - 1, 0);
        for (int i = 0; i < middle; i++)
        {
            tmp[i] = v[i];
        }
        for (int i = middle + 1; i < n; i++)
        {
            tmp[i - 1] = v[i];
        }
        v = tmp;
        n--;
        return x;
    }

    int popBack()
    {
        if (!n)
            return -1;
        int x = v.back();
        v.pop_back();
        n--;
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */