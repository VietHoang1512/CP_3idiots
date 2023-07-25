class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(), len2=nums2.size();
        map<long long, int> m1ii, m2ii, m1ij, m2ij;
        for(int i=0; i<len1; i++){
            for (int j=0; j<len1; j++){
                if (i==j) m1ii[(long long)nums1[i]*(long long)nums1[i]]++;
                else m1ij[(long long)nums1[i]*(long long)nums1[j]]++;
            }
        }
        for(int i=0; i<len2; i++){
            for (int j=0; j<len2; j++){
                if (i==j) m2ii[(long long)nums2[i]*(long long)nums2[i]]++;
                else m2ij[(long long)nums2[i]*(long long)nums2[j]]++;
            }
        } 
        int res=0;
        for (auto p:m1ii){
            res += p.second * m2ij[p.first]/2;
        }  
        for (auto p:m2ii){
            res += p.second * m1ij[p.first]/2;
        }   
        return res;    
    }
};