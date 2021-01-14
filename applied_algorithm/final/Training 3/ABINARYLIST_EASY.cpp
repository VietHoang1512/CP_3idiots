#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=0; i< (int) pow(2, n); ++i){
		int k = i;
		string result = "";
		for(int j=0; j<n; ++j){
			result.push_back('0' + k%2);
			k /= 2;
		}
		reverse(result.begin(), result.end());
		cout << result << endl;
	}		
}
