#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b)
{

    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl
         << gcd2(a, b);
    return 0;
}