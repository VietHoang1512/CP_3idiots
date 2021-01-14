#include <bits/stdc++.h>

using namespace std;
int const n_rows = 3;
const int n_cols = 4;
int arr[n_rows][n_cols]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

int main()
{
    // int B[] = {2,4,7,8,9,15};
    // int c, *p=&B[1];
    // c = *(--p);
    // cout << c << endl; // 4
    // cout << *p ;

    // *p+=1, c=*p--, p+=3, *p+=c;
    // for(int i=0; i<6;i++){
    //     cout << B[i] << " ";
    // }
    int n = n_rows * n_cols;
    for (int i = 0; i < n; i++)
    {
        cout << *(*(arr + i / n_cols) + i % n_cols) << " \n"[!((i+1) % n_cols)];
    }
}