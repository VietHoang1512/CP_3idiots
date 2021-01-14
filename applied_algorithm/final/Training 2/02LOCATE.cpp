#include<bits/stdc++.h>
using namespace std;

unsigned short find_max(int *first_image, int *second_image, int first_length, int second_length, int L, int C);

int main(){
	int L, C, T, length=0;
	cin >> T;
	
	unsigned short result[T];
	int inp;
	
	for(int i=0; i<T; i++){
		scanf("%d", &L);
		scanf("%d", &C);
		int first_image[10000], second_image[10000];
		int first_length=0, second_length=0;
		for(int j=0; j<L; j++)
			for(int k=0; k<C; k++){
				scanf("%d", &inp);
				if(inp)
					first_image[first_length++] = j * (2*C) + k;
			}
		for(int j=0; j<L; j++)
			for(int k=0; k<C; k++){
				scanf("%d", &inp);
				if(inp)
					second_image[second_length++] = (j + L) * (2*C) + k + C;
			}
		result[length++] = find_max(first_image, second_image, first_length, second_length, L, C);	
	}
	
	for(int i=0; i<T; i++)
		cout << result[i] << endl;
}

unsigned short find_max(int *first_image, int *second_image, int first_length, int second_length, int L, int C){
	unsigned short result[4*L*C] = {0};
	unsigned short max_result = 0;
	for(int itr2=0; itr2 < second_length; itr2++){
		int to = second_image[itr2];
		for(int itr1=0; itr1 < first_length; itr1++){
			int vector = to - first_image[itr1];
			result[vector]++;
			if(result[vector] > max_result)
				max_result = result[vector];
		}
	}
	return max_result;
}
