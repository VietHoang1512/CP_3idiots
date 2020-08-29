#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void lietKe(long n){
    vector<long> v;
    double tmp=0;   // log10(n!)

    for (int i=1; tmp<n+1 ;i++){
        //cout <<tmp << endl;
        tmp += log10(i);

        if (int(tmp)+1==n){
            v.push_back(i);
        }
    }

    if (!v.empty()){
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
    else cout << "NO";
}

int main(){
    long N;
    cin >> N;
    lietKe(N);
}