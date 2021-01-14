#include<bits/stdc++.h>
#define EPS 0.0000001
#define PI 3.14159265359
using namespace std;

int is_divide(int n, int f, double *radi, double S){
	int counter = 0;
	for(int i=0; i<n; ++i){
		counter += (int) (PI * radi[i] * radi[i] / S);
	}
	if(counter >= f+1)
		return 1;
	return 0;
}

double pie(int n, int f, double *radi){
	sort(radi, radi+n);

	double low = PI * radi[0] * radi[0] / (f+1);
	double high = PI * radi[n-1] * radi[n-1];
	double mid;
	
	while(high-low > EPS){
		mid = (low + high)/2;
		if(is_divide(n, f, radi, mid))
			low = mid;
		else
			high = mid;
	}
	
	return low;		
}

int main(){
	int T, N, F;
	cin >> T;
	
	double *radi;
	vector <double> result;
	
	for(int i=0; i<T; ++i){
		cin >> N >> F;
		radi = new double[N];
		
		for(int j=0; j<N; ++j)
			cin >> radi[j];
	
	result.push_back(pie(N, F, radi));
	}
	
	for(int i=0; i<T; ++i)
		printf("%.6lf\n", result[i]);
		
	return 0;
}
