#include <bits/stdc++.h>
using namespace std;

int find_first(long long & k, int n){
	if (n == 1)
		return 0;
	n--;
	int index;
	long long n_partial_fact = (long long) n;

	while (k >= n_partial_fact && n > 1) {
		n_partial_fact = n_partial_fact * (n - 1);
		n--;
	}

	index = k / n_partial_fact;
	k = k % n_partial_fact;

	return index;
}

void permutation(int n, long long k){
	set <int> s;
	for(int i=1; i<=n; ++i)
		s.insert(i);
	k--; // 0 base
	set<int>:: iterator itr = s.begin();
	for (int i = 0; i < n; i++) {
		int index = find_first(k, n - i);
		advance(itr, index);
		cout << *itr << " ";
		s.erase(itr);
		itr = s.begin();
	}
}

int main(){
	int n;
	long long k;
	cin >> n >> k;
	int fact=1;
	if(n <= 12){
		for(int i=1; i<=n; ++i)
			fact *= n;
		if(k > fact){
			cout << "-1" << endl;
			return 0;
		}
	}

	permutation(n, k);
	return 0;
}

