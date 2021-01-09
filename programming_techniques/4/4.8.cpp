#include <iostream>
#include <map>

using namespace std;

template <class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    std::map<int, double> x;
    std::map<int, double> _a = a, _b = b;
    for (auto e : _a)
    {
        x.insert({e.first, e.second});
    }
    for (auto e : _b)
    {
        if (_a.count(e.first))
        {
            x[e.first] = max(e.second, _a[e.first]);
            // x.insert({e.first, max(e.second, _a[e.first])});
            // cout << "*";
        }

        else
        {   
            // cout << "#";
            x.insert({e.first, e.second});
        }
    }
    return x;
}

template <class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    std::map<int, double> x;
    std::map<int, double> _a = a, _b = b;
    for (auto e : _a)
    {
        if (_b.count(e.first))
        {   
            x[e.first] = min(e.second, _b[e.first]);
            // x.insert({e.first, min(e.second, _b[e.first])});
        }
    }
    return x;
}

template <class T>
void print_fuzzy_set(const std::map<T, double> &a)
{
    cout << "{ ";
    for (const auto &x : a)
    {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main()
{
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = ";
    print_fuzzy_set(a);
    std::cout << "B = ";
    print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: ";
    print_fuzzy_set(c);
    std::cout << "Intersection: ";
    print_fuzzy_set(d);
}