#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include <cmath>
using namespace std;
 
const int mx=1000000;
int A[mx], dp[mx], tmp;
int main(){
 
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    if(n==1) {
        cout << A[0];
        return 0;
    }
    dp[0] = A[0];
    tmp = A[0];
    for(int i=1; i<n; i++){
        
        dp[i] = max(A[i], dp[i-1]+A[i]);
        tmp = max(tmp, dp[i]);
        // cout << dp[i] << "->\n";
    }
    cout << tmp;
    return 0;
}