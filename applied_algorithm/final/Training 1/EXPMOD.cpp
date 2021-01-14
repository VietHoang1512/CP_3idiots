#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long ExpMod(long long m, long long n);

int main(){
	string inp;
	getline(cin, inp);
	
	string a = ""; 
	string b = "";
	
	int i;
	for(i=0; i<inp.length(); i++){
		if(inp[i] != ' ')
			a.push_back(inp[i]);
		else
			break;
	}
	
	for(i++; i<inp.length(); i++)
		b.push_back(inp[i]);
		
	long long m, n;
	m = stoll(a);
	n = stoll(b);
	
	m %= mod;
	n %= mod-1;
	
	cout<< ExpMod(m, n);
	return 0;
}

long long ExpMod(long long m, long long n){
	if(!n)
		return 1;
		
	long long temp = ExpMod(m, n/2);
	temp = (temp * temp) % mod;
	
	if(n%2==1)
		return (m * temp)%mod;
	else
		return temp%mod;
}
