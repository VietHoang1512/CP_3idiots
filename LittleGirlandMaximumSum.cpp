#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >>q;
    /*
    vector <int> a,b;
    int ai;
    for(int i=1; i<=n; i++){
        cin >> ai;
        a.push_back(ai);
        b.push_back(0);
    }
    */
    int mx = 200000;
    long long a[mx], b[mx], util[mx];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    //TODO: reconstruct b's formula
    int l,r;
    for(int i=0; i<n; i++){
        util[i]=0;
    }

    for (int i=1; i<=q; i++){
        cin >> l >>r;
        l--; r--;
        util[l]++;
        if (r<n-1) util[r+1]--;
        /*
        for(int j=l; j<=r; j++){
            b[j-1]+=1;
        }
        */
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        cnt += util[i];
        b[i] = cnt;
    }


    sort(a, a+n, greater<long long>());
    sort(b, b+n, greater<long long>());

    long long sum =0;
    for(int i=0; i<n; i++){
        sum += a[i]*b[i];
    }
    cout << sum;
    /*
    cout << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << util[i] << " ";
    }
    */
    /*
    int n, q;
    cin >> n >>q;
    int a[200000], b[20000];
    for(int i=1; i<=n; i++){
        b[i] = 0;
    }

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int l,r;
    for (int i=1; i<=q; i++){
        cin >> l >>r;
        for(int j=l; j<=r; j++){
            b[j]+=1;
        }
    }
    */
}
