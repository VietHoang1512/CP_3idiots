#include<bits/stdc++.h>
using namespace std;

long long signal(vector<long long> a, int n, int b);

int main(){
	int n, b;
	string inp, temp = "";
	vector <long long> a;
	
	getline(cin, inp);
	for(int i=0; i<inp.size()+1; i++){
		if(inp[i] == ' ' || inp[i] == '\0'){
			if(inp[i] == ' ')
				n = stoi(temp);
			else
				b = stoi(temp);
			temp = "";
		}
		else 
			temp.push_back(inp[i]);
	}
	
	getline(cin, inp);
	for(int i=0; i<inp.size()+1; i++){
		if(inp[i] == ' ' || inp[i] == '\0'){
			a.push_back(stoi(temp));
			temp = "";
		}
		else
			temp.push_back(inp[i]);
	}
	
	cout << signal(a, n, b);
}

long long signal(vector<long long> a, int n, int b){
	vector <long long> maxb;
	vector <long long> maxe;
	long long m=-1;
	
	for(int i=0; i<n; i++){
		if(a[i]>m)
			m = a[i];
		maxb.push_back(m);
	}
	
	m=-1;
	for(int i=n-1; i>=0; i--){
		if(a[i]>m)
			m = a[i];
		maxe.push_back(m);
	}
	reverse(maxe.begin(), maxe.end());
	
	long long result=0;
	
	for(int i=1; i<n-1; i++){
		if(maxb[i-1] - a[i] >= b && maxe[i+1] - a[i]>=b){
			if(maxb[i-1] + maxe[i+1] - 2*a[i] > result)
				result = maxb[i-1] + maxe[i+1] - 2*a[i];
		}
	}
	
	if(!result)
		return -1;
	return result;
}
