#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class ProductOfNumbers
{
public:
    vector<int> v;

    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        v.push_back(num);
    }

    int getProduct(int k)
    {
        return accumulate(v.end() - k, v.end(), 1, multiplies<int>());
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */