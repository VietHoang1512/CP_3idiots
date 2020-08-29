#include <iostream>
using namespace std;

int main(){
    int n, a[1000], cmp[1000];
    cin >> n;

    if (n<3){
        cout << 0 ;
        return 0;
    }

    cin >> a[0];
    int cnt=0;
    for (int i=1; i<n; i++){
        cin >> a[i];
        if (a[i]>a[i-1]) cmp[i] = 1;
        else if (a[i]<a[i-1]) cmp[i] = -1;
        else cmp[i] = 0;
        //cout << cmp[i];
    }
    for (int i=1; i<n-1; i++){
        if (cmp[i]*cmp[i+1] == -1) cnt++;
    }
    cout << cnt;
}