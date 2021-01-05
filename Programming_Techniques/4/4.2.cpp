#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

// double distance(Point a, Point b)
// {
//     return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
// }

double area(Point a, Point b, Point c)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    double ab = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    double bc = sqrt((c.first - b.first) * (c.first - b.first) + (c.second - b.second) * (c.second - b.second));
    double ca = sqrt((a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second));
    double p = (ab + bc + ca) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

// int main()
// {
//     cout << setprecision(2) << fixed;
//     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
//     return 0;
// }