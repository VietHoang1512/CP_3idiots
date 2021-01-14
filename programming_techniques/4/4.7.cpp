#include <iostream>
#include <set>

using namespace std;

template <typename T>
set<T> set_union(const set<T> &a, const set<T> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    std::set<int> x;
    for (auto e : a)
        x.insert(e);
    for (auto e : b)
        x.insert(e);
    return x;
}

template <typename T>
set<T> set_intersection(const set<T> &a, const set<T> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    std::set<int> x;
    for (auto e : a)
    {
        if (b.count(e))
        {
            x.insert(e);
        }
    }
    return x;
}

template <typename T>
void print_set(const std::set<T> &a)
{
    for (const T &x : a)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);

    std::cout << "Union: ";
    print_set(c);
    std::cout << "Intersection: ";
    print_set(d);

    return 0;
}