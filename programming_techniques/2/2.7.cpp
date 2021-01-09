#include <iostream>
using namespace std;
void for_each(int *arr, int n, void (*func)(int))
{
    for (int i = 0; i < n; i++)
    {
        func(*(arr + i));
    }
}
int main()
{
    auto x1 = [](int i) -> int {
        return i;
    };
    cout << *x1;
}