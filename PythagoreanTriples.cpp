#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    if (n<3) cout << -1;
    else if (n%2==0){
        long long i = n*n/4;
        cout << i + 1  << " " << i - 1;
    }
    else{
        long long i = (n-1)/2;
        cout << 2*i*(i+1) << " " << 2*i*i + 2*i +1;
    }
}