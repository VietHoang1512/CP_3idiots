#include <bits / stdc++.h> 
using namespace std;
int a, b, c;
int *ptr;
int main()
{
    cout << "Enter three integers:" << endl;
    cin >> a >> b >> c;
    cout << "The three integers are:\n";
    ptr = &a;
    cout << "x = " << *ptr << endl;
    ptr = &b;
    cout << "y = " << *ptr << endl;
    ptr = &c;
    cout << "z = " << *ptr << endl;
}