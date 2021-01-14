#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a)
{
    for (int v : a)
        cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        if (*itr % 2 == 0)
        {
            a.erase(itr);
            itr--;
        }
    }
}

void sort_decrease(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), [](const int &x, const int &y) {
        return x > y;
    });
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> c;
    auto x = a.begin();
    auto y = b.begin();
    while ((x != a.end()) && (y != b.end()))
    {
        if (*x > *y)
        {
            if (c.empty() || (*x < c.back()))
            {
                c.push_back(*x);
            }
            x++;
        }
        else
        {
            if (c.empty() || (*y < c.back()))
            {
                c.push_back(*y);
            }
            y++;
        }
    }
    while (x != a.end())
    {
        if (c.empty() || (*x < c.back()))
        {
            c.push_back(*x);
        }
        x++;
    }
    while (y != b.end())
    {
        if (c.empty() || (*y < c.back()))
        {
            c.push_back(*y);
        }
        y++;
    }
    return c;
}

int main()
{
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}