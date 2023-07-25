#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string oddString(vector<string>& words) {
//         int total = words.size();
//         map<string, int> m;
//         vector<string> v;
//         for (auto w: words){
//             int len=w.size();
//             string s;
//             for(int j=0; j<len-1; j++){
//                 s += to_string(w[j+1]-w[j]);
//             }
//             m[s]++;
//             v.push_back(s);
            
//         }
//         for (int i=0; i<total; i++){
//             if(m[v[i]]==1) return words[i];
//         }
//         return "";
//     }
// };

class Solution {
public:
    string oddString(vector<string>& words) {
        int total = words.size(), len=words[0].size();
        vector<vector<int>> m(total, vector<int>(len-1, 0));
        vector<map<int, int>> cnt(len-1);
        for(int i=0; i<total; i++){
            for (int j=0; j<=len-2; j++){
                m[i][j] = words[i][j+1]-words[i][j];
                cnt[j][m[i][j]]++;
            }
        }

        for (int j=0; j<=len-2; j++){
            for(int i=0; i<total; i++){
                if (cnt[j][m[i][j]]==1)
                    return words[i];
            }
        }
       
        return "";
    }
};