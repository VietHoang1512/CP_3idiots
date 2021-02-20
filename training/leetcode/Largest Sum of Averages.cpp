class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int len = A.size();
        vector<double> B;
        for (auto x:A) B.push_back(x);


        
        // sort(B.rbegin(), B.rend());
        // double res=0;
        // if(len>K){
        //     for(int i=0; i<K-1; i++)
        //         res += B[i];
        //     for(int i=K-1; i<len; i++)
        //         res += B[i]/(len+1-K);  
        // }else{
        //     for(int i=0; i<len; i++)
        //         res += B[i];              
        // }
        // return res;
    }
};