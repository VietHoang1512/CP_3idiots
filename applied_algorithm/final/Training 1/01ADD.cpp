#include<bits/stdc++.h>
using namespace std;

string findSum(string str1, string str2) ;
string OwnSum(string s1, string s2);

int main(){
	string m, n;
	cin >> m;
	cin >> n;
	cout<< OwnSum(m,n);
}

string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string OwnSum(string s1, string s2){
	string result = "";
	int carry=0, sum;
	
	if(s1.length()>s2.length())
		swap(s1, s2);
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	
	for(int i=0; i<s1.length(); i++){
		sum = s1[i]-'0' + s2[i] - '0' + carry;
		carry = sum/10;
		result.push_back(sum%10+'0');
	}
	
	for(int i=s1.length(); i<s2.length(); i++){
		sum = s2[i] - '0' + carry;
		carry = sum/10;
		result.push_back(sum%10 + '0');
	}
	if(carry>0)
		result.push_back(carry+'0');
		
	reverse(result.begin(), result.end());
	
	return result;
}

