#include<bits/stdc++.h>
using namespace std;

long long waterjug(int a, int b, int c);
int waterjug_result(int m, int n, int d);

int gcd(int u, int v) 
{ 
    if (v==0) 
       return u; 
    return gcd(v, u%v); 
} 

int main(){
	int a, b, c, counter=0;
	string inp, num_temp = "";
	
	getline(cin, inp);
	for(int j=0; j<inp.size(); j++){
		if(inp[j] == ' '){
			if(!counter){
				counter++;
				a = stoi(num_temp);
			}
			else{
				counter=0;
				b = stoi(num_temp);
			}
				num_temp = "";
		}
		else
			num_temp.push_back(inp[j]);
	}
	c = stoi(num_temp);
	num_temp = "";

	cout << waterjug_result(a, b, c) << endl;
	
	return 0;
}
/*
long long waterjug(int first, int second, int d){
	int from = first; 
    int to = 0; 
  
    long long step = 1;
  
    while (from != d && to != d) { 
        int temp = min(from, second - to); 
  
        to   += temp; 
        from -= temp; 
  
        step++; 
  
        if (from == d || to == d) 
            break; 
  		if(from >0 && to >0 && to<second){
  			step += 2;
			to = from;
			from = 0; 	
		}
		else{
			if (from == 0) { 
            	from = first; 
            	step++; 
        	}
        	if (to == second) { 
            	to = 0; 
            	step++; 
        	} 
		}
    } 
    return step; 
}

int waterjug_result(int m, int n, int d) { 
    if (m > n) 
        swap(m, n); 
  
    if (d > n) 
        return -1; 
  
    if ((d % gcd(n,m)) != 0) 
        return -1; 
        
    return min(waterjug(n,m,d), waterjug(m,n,d));
} 
*/

long long waterjug(int m, int n, int d){
	long long amount, first=0, second=0, step=0;
	while(first!=d && second !=d){
		if(!first)
			first = m;
		else if(second==n)
			second = 0;
		else{
			amount = min(first, n-second);
			first -= amount;
			second += amount;
			
		}
		step++;
	}
	return step;
}

int waterjug_result(int m, int n, int d){
	if(m<n)
		swap(m,n);
	if(m<d)
		return -1;
	if(d % gcd(m,n) != 0)
		return -1;
	return min(waterjug(m,n,d), waterjug(n,m,d));
	
}

