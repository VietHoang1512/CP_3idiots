#include <iostream>
using namespace std;

bool kiemTra(long n)
{
    if (n == 2)
        return true;
    else if ((n < 2) || (n % 2 == 0))
        return false;
    else
    {
        for (long i = 1; (2 * i + 1) * (2 * i + 1) <= n; i++)
        {
            if (n % (2 * i + 1) == 0)
                return false;
        }
    }

    return true;
}

int main()
{
    long a, b;
    cin >> a >> b;
    for (long i = a; i <= b; i++)
    {
        if (kiemTra(i))
            cout << i << endl;
    }
}