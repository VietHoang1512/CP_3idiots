#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int len = queries[0].size();
        vector<string> res;
        for(auto query:queries){
            for (auto dict:dictionary){
                int dif = 0;
                for(int i=0; i<len; i++){
                    dif += (!(query[i]==dict[i]));
                }
                if (dif<=2){
                    res.push_back(query);
                    break;
                }
            }
        }
        return res;
    }
};