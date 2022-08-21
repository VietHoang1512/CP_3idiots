#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class SmallestInfiniteSet
{
public:
    map<int, int> poped;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int i = 0;
        while (++i)
        {
            if (poped.find(i) == poped.end())
            {
                poped[i]=1;
                return i;
            }
        }
        return 0;
    }

    void addBack(int num)
    {
        if(poped.find(num)!=poped.end())
        {
            poped.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */