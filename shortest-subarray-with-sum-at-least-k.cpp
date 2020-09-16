class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int mx=50001;
        int dp[mx], s[mx];
        int len = A.size(), tmp=0;
        deque<int> d;
        s[0] = tmp;
        for(int i=0; i<len; i++){
            // dp[i]=-10000;
            tmp += A[i];
            s[i+1] = tmp;
            if (A[i]>=K) return 1;
        }
        // cout << "sum \n";
        for(int i=0; i<len+1; i++){
            cout << s[i] << " ";
        } 
        // cout << "\n";
        if (len<=1) return -1;
//          Brute-force with prefix-sum   
        // for(int i=0; i<len; i++){
        //     for(int j=i+1; j<len; j++){
        //         dp[j-i] = max(dp[j-i], s[j] - s[i] + A[i]);
        //     } 
        // }
        
        // for(int i=1; i<len; i++){
        //     if(dp[i]>=K)    return i+1;
        // }
        int ans=len+1;
        
        for(int i=0; i<len+1; i++){
            
            while((d.size())&&(s[d.back()]>=s[i])){
                // cout << "pop back " << d.back() << endl;
                d.pop_back();
            }
            
            while((d.size())&&(s[i]-s[d.front()]>=K)){

                ans = min(ans, i-d.front());
                // cout << "ANS: " << ans << endl;
                // cout << "pop front " << d.front() << endl;
                d.pop_front();
            }
            // cout << "Push " << i << endl;
            d.push_back(i);
        }
        // for(int i:d){
        //     cout << i << " ";
        // }
        // cout << "\n" << ans;
        return (ans<=len)?ans:-1;
    }
};

