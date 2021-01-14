#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main(){
	long n;
	string inp;
	
	//Input
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, inp);
	
	//Process
	long long result=0, num;
	string temp = "";
	
	for(long i = 0; i < inp.length(); i++){
		if(inp[i]!=' ')
			temp.push_back(inp[i]);
		else{ 
			// inp[i] is space character
			num = stoll(temp);
			if(result+num>mod)
				result += num-mod;
			else
				result += num;
			temp = "";
		}
	}
	num = stoll(temp);
	if(result+num>mod)
		result += num-mod;
	else
		result += num;
	
	// Output the result
	cout<< result;
	
	return 0;
}

