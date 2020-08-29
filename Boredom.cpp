#include <iostream>

using namespace std;

int main(){
    int n, ai, mx=0;
    int a[100000];
    int p[100000];

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> ai;
        a[ai]+=1;
        mx = max(mx, ai);
    }
    p[0] = 0;
    p[1] = a[1];

    for (int i=2; i<=mx; i++){
        p[i] = max(p[i-1], p[i-2] + a[i]*i);
    }
    cout << p[mx];
}