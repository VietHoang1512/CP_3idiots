#include<bits/stdc++.h>
using namespace std;

long long w, c;
long long way[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
long long note[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};

void sub_atm(long long w, long long &res_way, long long &res_note){
	long long temp_way=1;
	long long temp_note=(w-1)/5+1;
	if(w % 5 == 4){
		++temp_note;
		temp_way = 3;
	}
	else if(w % 5 == 1){
		temp_way = 2;
	}
	if(w == 1){
		temp_way = 1;
	}
	else if(w == 4){
		temp_way = 2;
	}
	res_way = temp_way;
	res_note = temp_note;
}

void atm(){
	long long res_way=1, res_note=0;
	for(int i=0; i<c && w>0; ++i){
		int digit = w%10;
		res_way *= way[digit];
		res_note += note[digit];
		w /= 10;
	}
	
	if(w){
		long long x, y;
		sub_atm(w, x, y);
		res_way *= x;
		res_note += y;
	}
	cout << res_note << " " << res_way << endl;
}

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; ++i){
		scanf("%lld%lld", &w, &c);
		if(w % 1000)
			cout << 0 << endl;
		else{
			w /= 1000;
			atm();
		}
	}
	
}
