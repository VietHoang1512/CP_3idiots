#include <iostream>

using namespace std;
int f(int n, int k)
{
    static int x = 1;
    if (k > 0)
    {
        x*=(n-k+1);
        x/=k;
    }
    return x;
    x ['g']
}
int main() {
    int n = 6;
    for(int i=0; i<7; i++)
    {
        cout <<f(n,i) <<" ";
    }
    return 0;
}