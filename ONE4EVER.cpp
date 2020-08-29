#include <iostream>
using namespace std;

long long T, a, b, m, k, res;

struct MaTran2d{
    long long M[2][2];
    MaTran2d(){
        //M[0][0] = a; //= 0
        M[0][1] = 0;
        M[1][0] = 1;
        M[1][1] = 1;
    }
};

MaTran2d operator * (MaTran2d A, MaTran2d B){
    MaTran2d res;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            res.M[i][j] = (A.M[i][0]*B.M[0][j] + A.M[i][1]*B.M[1][j])%m;
        }
    }
    return res;
}

MaTran2d luyThuaN(MaTran2d A, long n){
    if (n==0){  // ma tran don vi
        MaTran2d res;
        res.M[0][0] = 1;
        res.M[1][0] = 0;
        return res;
    }
    else if (n==1)
        return A;
    else if (n%2==1)
        return luyThuaN(A, n-1)*A;
    return luyThuaN(A, n/2)*luyThuaN(A, n/2);
}

int main(){
    MaTran2d A, An;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >>a >>b >>m >>k;
        A.M[0][0] = a;
        An = luyThuaN(A, k-1);
        res = b*(An.M[0][0] + An.M[1][0])%m;
        cout <<res <<endl;
    }
}