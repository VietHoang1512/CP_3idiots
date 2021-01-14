#include<bits/stdc++.h>
using namespace std;

vector <unsigned long long> split_string(string inp);
unsigned long long hist(vector <unsigned long long> arr);

int main(){
	string temp;
	vector <vector <unsigned long long>> inp;
	 
	while(1){
		getline(cin, temp);
		if(!temp.compare("0"))
			break;
		inp.push_back(split_string(temp));
	}
	
	for(unsigned long long i=0; i<inp.size(); i++)
		cout << hist(inp[i]) << "\n";
}

vector <unsigned long long> split_string(string inp){
	string temp = "";
	vector <unsigned long long> result;
	unsigned long long i;
	
	for(i=0; i<inp.size(); i++)
		if(inp[i] == ' ')
			break; // Find first space character
	
	for(i++; i<inp.size()+1; i++){
		if(inp[i] == ' ' || inp[i] == '\0'){
			result.push_back(stoi(temp));
			temp = "";
		}
		temp.push_back(inp[i]);
	}
	return result;
}

/*
unsigned long long hist(vector <unsigned long long> arr){
	unsigned long long n = arr.size();
    stack<unsigned long long> s; 
  
    unsigned long long result = 0;
    unsigned long long tp; 
    unsigned long long area_with_top; 
  
    unsigned long long i = 0; 
    while (i<n) 
    { 
        if (s.empty() || arr[s.top()] <= arr[i]) 
            s.push(i++); 
        else
        { 
            tp = s.top();
            s.pop(); 
            area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1); 
            if (result < area_with_top) 
                result = area_with_top; 
        } 
	}
	  while (s.empty() == false) { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1); 
  
        if (result < area_with_top) 
            result = area_with_top; 
    } 
  
	return result;
}
*/

unsigned long long hist(vector <unsigned long long> arr){
	stack <unsigned long long> s;
	unsigned long long tp=0;
	int n = arr.size();
	unsigned long long result=0, area;
	
	int i=0;
	while(i<n){
		if(s.empty() || arr[s.top()] <= arr[i])
			s.push(i++);
		else{
			tp = s.top();
			s.pop();
			area = arr[tp] * (s.empty()? i : (i-s.top()-1));
			if(area > result)
				result = area;
		}
	}
	while(!s.empty()){
		tp = s.top();
		s.pop();
		area = arr[tp] * (s.empty()? i : i-s.top()-1);
		if(area > result)
			result = area;
	}
	return result;
}
