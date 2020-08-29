#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
const int mx=100;
int main(){
    int n_test;
    int n, m;
 
    long long t[mx], l[mx], h[mx];
    long long max_temp[mx], min_temp[mx];
    cin >> n_test;
    for (int test=0; test<n_test; test++){
        int tmp=0;
        cin >>n >>m;
        
        //cout << endl << "On test " << test+1 << endl;
        // first customer
        cin >> t[0] >> l[0] >>h[0];
 
        min_temp[0] = m - t[0];
        max_temp[0] = m + t[0];
 
        if((min_temp[0]>h[0])||(max_temp[0]<l[0])){
            cout << "NO" << endl;
            continue;
        }
        
        min_temp[0] = max(min_temp[0], l[0]);
        max_temp[0] = min(max_temp[0], h[0]);
        //cout << "Time "<< t[0]<< ": " << min_temp[0] << "->" << max_temp[0] << endl;
        
        // i th customer
        
        for(int i=1; i<n; i++){
            cin >> t[i] >> l[i] >>h[i];
 
            min_temp[i] = min_temp[i-1] - (t[i] - t[i-1]);
            max_temp[i] = max_temp[i-1] + (t[i] - t[i-1]);
 
            if ((min_temp[i]>h[i])||(max_temp[i]<l[i])){
                cout << "NO" << endl;
                tmp++;
                break;
            }
            
            min_temp[i] = max(min_temp[i], l[i]);
            max_temp[i] = min(max_temp[i], h[i]);
            //cout << "Time " << t[i]<< ": " << min_temp[i] << "->" << max_temp[i] << endl;
            
        }
        if (!tmp)cout << "YES"<< endl;
    }
}
