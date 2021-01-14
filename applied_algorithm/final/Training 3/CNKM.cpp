#include<bits/stdc++.h>
using namespace std;

unsigned long long m;

unsigned long long mul_mod(unsigned long long a, unsigned long long b, unsigned long long m){
	unsigned long long result=0, digit, temm;
	a = a%m;
	
	while(b){
		digit = b%10;
		temm = (a * digit) % m;
		result = (result + temm) %m;
		a = (a*10) % m;
		b /= 10;
	}
	
	return result;
}

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long m) { 
    unsigned long long res = 1; 
  
    x = x % m; 
  
    while (y > 0) { 
        if (y & 1) 
            res = mul_mod(res, x, m);
        y = y >> 1; 
        x = mul_mod(x, x, m);
    } 
    return res; 
} 
  

unsigned long long modInverse(unsigned long long n, unsigned long long m) { 
    return power(n, m - 2, m); 
} 
  
unsigned long long bi_coeff_mod(unsigned long long n, unsigned long long k, unsigned long long m) { 
    if (k == 0) 
        return 1; 
  
    n = n%m;
    unsigned long long fac, num;
    fac = 1; 
	num = 1;
    for (unsigned long long i = 1; i <= k; i++) {
    	num = mul_mod(num, n-i+1, m);
    	fac = mul_mod(fac, i, m);
	}
    return mul_mod(num, modInverse(fac, m), m); 
} 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	m = 1000000007;
	unsigned long long n, k;
	cin >> k >> n;
	unsigned long long result = bi_coeff_mod(n, k, m);
	
	cout << result << endl;
}
