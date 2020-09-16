#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include <cmath>
using namespace std;
 
 
const long long p=1000000007;
int main(){
    long long a,b,c=1;
    cin >>a >>b;
    b = b%(p-1);
    a = a%p;
 
    if (b==0){
        cout << 1;
        return 0;
    }
 
    for (int i=0; i<b; i++){
 
        c = (c*a)%p;
    }
    cout << c;
}