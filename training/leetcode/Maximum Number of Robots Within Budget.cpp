#include <bits/stdc++.h>
using namespace std;

long long main()
{
}


class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long n = chargeTimes.size();
        int res=0;
        int start=0, end=0;
        long long run_cost=0;
        
        queue<long long> q;
        deque<long long> dq;
        
        for(long long i=0; i<n; i++){
            if(chargeTimes[i]+runningCosts[i]<=budget){
                res++;
                dq.push_back(i);
                q.push(i);
                start=i;
                end=i;
                run_cost = runningCosts[i];
                break;
            }
        }
                // cout << "\nDONE:" << start << "->" << end << endl;

        if(dq.empty()) return 0;
        while(1){
            end++;
            if(end>=n) break;
            if(q.empty()){
                q.push(end);
                dq.push_back(end);
            }else{
                q.push(end);
                while(!dq.empty()&&chargeTimes[dq.back()]<=chargeTimes[end]) dq.pop_back();
                dq.push_back(end);                
            }

            run_cost += runningCosts[end];
            while((!dq.empty())&&(chargeTimes[dq.front()]+(end-start+1)*run_cost>budget)){
                run_cost -= runningCosts[start];
                start++;

                if(q.front()==dq.front()) dq.pop_front();
                q.pop();
            }
            // cout << start << "->" << end << endl;
            res = max(res, end-start+1);

        }
        // cout << "\n***\n";
        return res;
    }
};