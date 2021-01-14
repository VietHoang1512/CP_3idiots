#include<bits/stdc++.h>
using namespace std;

long long Count(string source, string key){
	long long result=0;
	int i;
	while((i = source.find(key)) != -1){
		result++;
		source = source.substr(i+1);
	}
	return result;
}

long long FibWords(int n, string p){
	long long result=0;
	int i=1; // Current F[i+1] taking account
	string F1="1"; // Use to store F[i+1]
	string F0="0"; // Use to store F[i]
	string R1; // Use to store the remain of F1 from (length - 1) last positions for odd
	string R0; // Use to store the remain of F0 from (length - 1) last positions for even
	string B; // Use to store the beginning of F1 for (length - 1) positions
	string temp; // Use for caching
	long long L1=1; // Use to store length of F[i+1]
	long long L0=1; // Use to store length of F[i]
	long long l_temp; // Use for caching
	long long C1, C0; // Use to store number of occurrence of p in F[i+1], F[i], respectively
	int length=p.size();
	
	// Find the first position i such that length of F[i], F[i+1] exceeds length of p
	while((int) F0.size() < length){
		temp = F1;
		F1 += F0;
		F0 = temp;
		++i;
		l_temp = L1;
		L1 += L0;
		L0 = l_temp;
		if(i >= n) // F[n] has length may not equal to p
			return Count(F1, p);
	}
	
	B = F1.substr(0, length-1); // Every F[k] with k>=i has same length start
	R1 = F1.substr(L1 - length + 1) + B; // Every F[i+1], F[i+3], F[i+5],... has same length ending
	R0 = F0.substr(L0 - length + 1) + B; // Every F[i], F[i+2], F[i+4], ... has same length ending
	long long M1 = Count(R1, p); // Number of occurence of mid-pattern F[i+1], F[i+3], F[i+5], ...
	long long M0 = Count(R0, p); // Number of occurence of mid-pattern F[i], F[i+2], F[i+4], ...
	
	C1 = Count(F1, p);
	C0 = Count(F0, p);
	
	for(int k=i+1; k<=n; ++k){
		l_temp = C1;
		C1 += C0;
		C0 = l_temp;
		// Choose the proper mid-pattern
		if((k-i) % 2)
			C1 += M1;
		else
			C1 += M0;
	}
	
	return C1;
}

int main(){
	int n;
	string p;
	vector <long long> result;
	
	while(cin >> n >> p)
		result.push_back(FibWords(n, p));
	
	int T=result.size();
	for(int i=0; i<T; ++i)
		cout << "Case " << i+1 << ": " << result[i] << endl;
		
	return 0;
}
