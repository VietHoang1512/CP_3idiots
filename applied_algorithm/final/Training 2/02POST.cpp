#include<bits/stdc++.h>
using namespace std;

long long post_man(long long n, long long k, vector <long long> pos, vector <long long> pack);

int main(){
	long long n, posi=0, nega=0, k, temp_number, signal;
	vector <long long> posi_pos, nega_pos, posi_pack, nega_pack;
	string inp, temp = "";
	
	getline(cin, inp);
	for(long long i=0; i<inp.size(); i++){
		if(inp[i] == ' '){
			n = stoi(temp);
			temp = "";
		}
		else
			temp.push_back(inp[i]);
	}
	k = stoi(temp);
	temp = "";
	
	for(long long i=0; i<n; i++){
		getline(cin, inp);
		for(long long j=0; j<inp.size(); j++){
			if(inp[j] == ' '){
				temp_number = stoi(temp);
				if(temp_number >= 0){
					posi++;
					posi_pos.push_back(temp_number);
					signal = 1;
				}
				else{
					nega++;
					nega_pos.push_back(-temp_number);
					signal = -1;
				}
				temp = "";
			}
			else
				temp.push_back(inp[j]);
		}
		if(signal>0)
		 	posi_pack.push_back(stoi(temp));
		else
			nega_pack.push_back(stoi(temp));
		temp = "";
	}
	
	cout << post_man(posi, k, posi_pos, posi_pack) + post_man(nega, k, nega_pos, nega_pack);
	return 0;
}

long long post_man(long long n, long long k, vector <long long> pos, vector <long long> pack){
	long long min, temp, swap;
	for(long long i=0; i<n-1; i++){
		temp = 0;
		min = pos[i];
		for(long long j=i+1; j<n; j++)
			if(pos[j] < min){
				min = pos[j];
				temp = j;
			}
		if(temp){
			swap = pos[i];
			pos[i] = pos[temp];
			pos[temp] = swap;
			
			swap = pack[i];
			pack[i] = pack[temp];
			pack[temp] = swap;
		}
	}
	
	long long distance=0;
	long long time, remain=0;
	
	for(long long i=n-1; i>=0; i--){
		if(pack[i] < remain){
			remain -= pack[i];
		}
		else{
			pack[i] -= remain;
			time = (pack[i]+k-1)/k;
			distance = distance + 2 * time * pos[i];
			remain = time * k - pack[i];
		}
	}
	return distance;
}
