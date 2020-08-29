#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

const int mx=400000;
int main(){
    long long n;
    long long b[mx], c[mx];
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >>b[i];
        b[i]-=i;
        c[b[i]]=0;
    }

    long long res=0;
    for (int i=1; i<=n; i++){
        c[b[i]]+=b[i]+i;
    }

    for (int i=1; i<=n; i++){
        res = max(res, c[b[i]]);
    }
    cout << res;


    /*

    c[1] = b[1];
    int tmp = c[1];
    //cout << b[1];
    for (int i=2; i<=n; i++){
        int mx_sum=0;
        for (int j=1; j<i; j++){

            if((b[i]-b[j])==i-j){
                mx_sum = max(mx_sum,c[j]+b[i]);
            }
        }
        c[i] = max(mx_sum, b[i]);
        //cout << " " << c[i] ;
        tmp = max(tmp, c[i]);
    }
    cout << tmp;
    */
}
