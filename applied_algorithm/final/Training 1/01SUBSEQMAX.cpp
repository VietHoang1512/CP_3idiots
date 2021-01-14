#include <bits/stdc++.h>
#include<string>

using namespace std;

vector<string> split_string(string);

long long MaxSubsequence(vector <long long> array){
	vector <long long> temp(array.size());
	long long result = 0;
	temp[0] = result = array[0];
	for(int i = 1; i < array.size(); i++){
		temp[i] = max(array[i], array[i] + temp[i-1]);
		result = max(temp[i], result);
	}
	return result;
}

int main(){
	int n; 
	cin>>n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	string arr_temp_temp;
	getline(cin, arr_temp_temp);
	
	vector<string> arr_temp = split_string(arr_temp_temp);
	
	vector<long long> arr(n);
	
	for(int i = 0; i < n; i++){
		int temp = stoi(arr_temp[i]);
		arr[i] = temp;
	}
	
	cout<<MaxSubsequence(arr);
	return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
