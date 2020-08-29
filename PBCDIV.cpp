#include <iostream>
using namespace std;

long dem (long A, long B, long n){
    return (B/n - (A-1)/n);
}

long soThoaMan(long A, long B){
    return dem(A,B,12) + dem(A,B,30) - 2*dem(A,B,60);
}

int main(){
    long N, A, B, cnt;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A >> B;
        cout << soThoaMan(A,B) << endl;
    }
}