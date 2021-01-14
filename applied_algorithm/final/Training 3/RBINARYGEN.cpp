#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	string inp;
	getline(cin, inp);
	
	int length = inp.size(), i;
	bool found = false;
	for(i=length-1; i>=0; --i){
		if(inp[i] == '0'){
			found = true;
			break;
		}
	}
	if(!found)
		cout << "-1" << endl;
	else{
		inp[i] = '1';
		for(++i; i<length; ++i)
			inp[i] = '0';
		cout << inp << endl;
	}
}
