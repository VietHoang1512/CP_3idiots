#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

struct bigNum
{
    char sign;
    char num[101];
};

bigNum get_value(long long n)
{
    bigNum a;
    a.sign = (n > 0) + '0';
    if (n <= 0)
    {
        n = -n;
    }

    for (int j = 100; j >= 0; j--)
    {
        a.num[j] = n % 10 + '0';
        n = n / 10;
    }
    return a;
}

bigNum operator+(bigNum a, bigNum b)
{
    bigNum c;
    int s, k = 0;
    if (a.sign == b.sign)
    {
        c.sign = a.sign;
        for (int i = 100; i >= 0; i--)
        {
            s = (a.num[i] - '0') + (b.num[i] - '0') + k;
            c.num[i] = s % 10 + '0';
            k = s / 10;
        }
    }
    else
    {
        for (int i = 100; i >= 0; i--)
        {
            s = (a.num[i] - '0') - (b.num[i] - '0') + k;
            if (s < 0)
            {
                s += 10;
                k = -1;
            }
            else
            {
                k = 0;
            }
            c.num[i] = s % 10 + '0';
        }

        c.sign = ((a.sign - '0' - k) == 1) + '0';
        if (k == -1)
        {
            k = 0;
            for (int i = 100; i >= 0; i--)
            {
                s = -(c.num[i] - '0') + k;
                if (s < 0)
                {
                    s += 10;
                    k = -1;
                }
                else
                {
                    k = 0;
                }
                c.num[i] = s % 10 + '0';
            }
        }
    }
    return c;
}

bigNum operator-(bigNum a, bigNum b)
{
    bigNum c;
    c.sign = 1 - (b.sign - '0') + '0';
    for (int i = 0; i <= 100; i++)
    {
        c.num[i] = b.num[i];
    }
    return a + c;
}

bigNum operator+(bigNum a, long long n)
{
    bigNum b = get_value(n);
    return a + b;
}

bigNum operator-(bigNum a, long long n)
{
    bigNum b = get_value(-n);
    return a + b;
}

bigNum operator*(bigNum a, bigNum b)
{
    bigNum c;
    c.sign = (a.sign == b.sign) + '0';
    int s, k = 0;
    for (int i = 100; i >= 0; i--)
    {
        s = 0;
        for (int j = 100; j >= i; j--)
        {
            s += (a.num[j] - '0') * (b.num[i + 100 - j] - '0');
        }
        s += k;
        c.num[i] = s % 10 + '0';
        k = s / 10;
    }
    return c;
}

bigNum operator*(long long n, bigNum a)
{
    bigNum b = get_value(n);
    return b * a;
}

bool operator==(bigNum a, bigNum b)
{
    if (a.sign != b.sign)
    {
        return false;
    }

    for (int i = 0; i <= 100; i++)
    {
        if (a.num[i] != b.num[i])
        {
            return false;
        }
    }
    return true;
}

ostream &operator<<(ostream &out, const bigNum &a)
{
    out << a.sign;

    int i;
    for (i = 0; i <= 100; i++)
    {
        if (a.num[i] != '0')
        {
            break;
        }
    }

    for (int j = i; j <= 100; j++)
    {
        out << a.num[j];
    }
    return out;
}

istream &operator>>(istream &in, bigNum &a)
{
    string s;
    in >> s;
    int j = 100;
    a.sign = s[0];
    for (int i = int(s.length() - 1); i > 0; i--)
    {
        a.num[j] = char(s[i]);
        j--;
    }
    for (int i = j; i >= 0; i--)
    {
        a.num[i] = '0';
    }
    return in;
}

int main()
{
    bigNum a, b, c;
    cin >> a;
    cin >> b;
    c = a * b - 3 * a + 4 * b;
    cout << c;
    return 0;
}