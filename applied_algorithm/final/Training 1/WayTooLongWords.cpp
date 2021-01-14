#include<bits/stdc++.h>
using namespace std;

void ConvertLongWord(string word);

int main(){
	int n;
	cin >> n;
	vector <string> inp;
	string temp;
	
	for(int i=0; i<n; i++){
		cin >> temp;
		inp.push_back(temp);
	}
	
	for(int i=0; i<n; i++)
		ConvertLongWord(inp[i]);
	return 0;
}

void ConvertLongWord(string word){
	int length = word.length();
	if(length <= 10){
		cout << word <<"\n";
		return;
	}
	cout << word[0];
	cout << length-2;
	cout << word[length-1] <<"\n";
	
}
