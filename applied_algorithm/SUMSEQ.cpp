#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include <cmath>
using namespace std;
 
const long long x = 1000000007;
 
long long res=0, tmp;
int n;
int main(){
    cin >>n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        res = (long long)(res+tmp)%x;
    }
    cout << res;
}