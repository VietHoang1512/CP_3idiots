#include <iostream>
#include <cmath>
using namespace std;
long long t, n, x, d,h;
long long max_dif, max_d;
long long cnt;
 
int main(){
    cin >> t;
    for (int query=0; query<t; query++){
        cin >> n>> x;
        //max_dif = -100000000;
        //max_d = 0;
 
        cin >> d >> h;
        max_d = d;
        max_dif = d-h;
 
        for (int i=1; i<n; i++){
            cin >> d >> h;
            max_d = (long long) max(max_d, d);
            max_dif = (long long) max(max_dif, d-h);
        }
 
        if (x<=max_d){
            cout << 1 << endl;
            continue;
        }
        
        if (max_dif<=0){
            cout << -1 << endl;
            continue;
        }
        
        x -= max_d;
        cout << (long long) 2 + (x-1)/max_dif << endl;
        //cout << "__________________________________" << endl;
    }
}