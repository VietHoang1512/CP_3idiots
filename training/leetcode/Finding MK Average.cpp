#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class MKAverage
{
public:
    int M, K, size = 0;
    MKAverage(int m, int k)
    {
        M = m, K = k;
    }

    void addElement(int num)
    {
        size++;
    }

    int calculateMKAverage()
    {
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */