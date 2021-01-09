#include <iostream>
#include <vector>
using namespace std;

vector<long long> A, B, C;
long long N, M;
long long res;

int main()
{

    cin >> N;
    A.resize(N + 1);
    for (int i = 0; i <= N; ++i)
    {
        cin >> A[i];
    }

    cin >> M;
    B.resize(M + 1);
    for (int i = 0; i <= M; ++i)
    {
        cin >> B[i];
    }

    C.resize(N + M + 1);
   
    for (int i = 0; i <= N ; ++i)
    {
        for (int j = 0; j<=M; ++j)
        {
            C[i+j] += A[i] * B[j];
        }    
    }
    res = C[0];
    for (int i=1; i<=M+N; i++) 
        res = res ^ C[i];
    cout << res <<endl;
    return 0;
}