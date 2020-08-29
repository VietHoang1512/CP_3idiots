#include <iostream>
using namespace std;

int chuanHoa(long k, long x){
    long tmp = x%k;
    if (tmp<0) return tmp + k;
    return tmp;
}

int main(){
    long n,k, a[1000], M[50][1000];
    cin >> n >> k;

    for (int i=0; i<n; i++){
        cin >> a[i];
        a[i]%=k;
    }

    for (int i=0; i<k; i++){
        M[i][0]=0;
    }

    for (int j=1; j<n; j++){
        for (int i=0; i<k; i++){
            M[i][j] = max(M[i][j-1], M[chuanHoa(k, i-a[j])][j-1] + 1);
        }
    }

    cout << M[0][n-1];
}