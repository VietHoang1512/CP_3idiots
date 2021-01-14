#include<bits/stdc++.h>
using namespace std;

void bracket_sequence(string inp, int n);
int count_bracket(string inp);

int main(){
	string inp;
	getline(cin, inp);
	
	bracket_sequence(inp, inp.size());
}

void bracket_sequence(string inp, int n){
	stack <char> s;
	vector <string> possible_result;
	string possible = "";
	
	int max_result=0, pair=0;
	
	for(int i=0; i<n; i++){
		if(inp[i] == '(' || inp[i] == '['){
			s.push(inp[i]);
			possible.push_back(inp[i]);
		}		
		else{
			if(s.empty()){
				int length = possible.size();
				possible_result.push_back(possible.substr(length-2*pair, 2*pair));
				possible = "";
				pair=0;
				continue;
			}
				
			char temp = s.top();
			s.pop();
			
			if(((inp[i] ==')') && (temp == '(')) || ((inp[i] == ']') && (temp == '['))){
				possible.push_back(inp[i]);
				pair++;
			}
			else{
				int length = possible.size();
				possible_result.push_back(possible.substr(length-2*pair, 2*pair));
				while(!s.empty())
					s.pop();
				possible = "";
				pair=0;
			}
		}
	}
	
	int length = possible.size();
	possible_result.push_back(possible.substr(length-2*pair, 2*pair));
	
		
	for(string s: possible_result)
		if (count_bracket(s) > max_result)
			max_result = count_bracket(s);
			
	cout << max_result << endl;		
	if(!max_result)
		cout << endl;
	else
		for(string s: possible_result)
			if(count_bracket(s) == max_result){
				cout << s << endl;
				break;
			}
}

int count_bracket(string inp){
	int result=0;
	for(int i=0; i<inp.size(); i++)
		if(inp[i] == '[')
			result++;
	return result;
}
