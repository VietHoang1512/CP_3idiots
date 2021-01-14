#include<bits/stdc++.h>
using namespace std;

void Queue(vector <unsigned int> a, int n);
int binary_search(unsigned int a[], int begin, int end, int key);

int main(){
	int n;
	string inp, temp = "";
	vector <unsigned int> a;
	
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	getline(cin, inp);
	for(int i=0; i<inp.size()+1; i++){
		if(inp[i] == ' ' || inp[i] == '\0'){
			a.push_back(stoi(temp));
			temp = "";
		}
		else
			temp.push_back(inp[i]);
	}
	
	Queue(a, n);
}

void Queue(vector <unsigned int> a, int n){
	reverse(a.begin(), a.end());
	unsigned int temp = a[0];
	
	vector <int> result;
	int length=1;
	unsigned int m[n];
	
	result.push_back(-1);
	m[0] = a[0];
	
	for(int i=1; i<n; i++){
		if(a[i] < temp)
			temp = a[i];
		m[length++] = temp;
		
		if(a[i] == a[i-1])
			result.push_back(result[i-1]);
		else{
			int pos = binary_search(m, 0, i-1, a[i]);
			if(pos == i-1)
				result.push_back(-1);
			else
				result.push_back(pos+1);
		}
	}

	string display = "";
	for(int i=n-1; i>=0; i--){
		if(result[i] == -1)
			display += "-1";
		else
			display += to_string(i-result[i]-1);
		if(i>0)
			display += " ";
	}
	cout << display;

}

int binary_search(unsigned int m[], int begin, int end, int key){
	int mid;
	if (m[begin] < key)
		return -1;
	while(begin < end){
		mid = (begin + end)/2;
		if(m[mid] >= key)
			begin = mid;
		else
			end = mid-1;
		if(begin == end-1){
			if(m[end] >=key)
				return end;
			return begin;
		}		
	}
	return begin;	
}
