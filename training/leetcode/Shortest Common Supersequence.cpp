#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {

        string dp[1005][1005];

        int lenght1 = string1.size(), lenght2 = string2.size();
        string string1 = str1;
        string string2 = str2;
        for (int x = 0; x < lenght1; x++)
        {
            for (int y = 0; y < lenght2; y++)
            {   
                str1 = "", str2 = "";

                for(int i=x; i<len1)
                int len1 = str1.size(), len2 = str2.size();
                str1 = "0" + str1;
                str2 = "0" + str2;
                for (int i = 1; i <= len1; i++)
                {
                    for (int j = 1; j <= len2; j++)
                    {

                        if (str1[i] == str2[j])
                        {
                            dp[i][j] = dp[i - 1][j - 1] + str1[i];
                        }
                        else
                        {
                            int l1 = dp[i - 1][j].size();
                            int l2 = dp[i][j - 1].size();
                            if (l1 < l2)
                                dp[i][j] = dp[i][j - 1];
                            else
                                dp[i][j] = dp[i - 1][j];
                        }
                    }
                }
            }
        }

        return dp[len1][len2];

        //         int len1 = str1.size(), len2 = str2.size();
        //         bool overlap = true;
        //         int res=0;
        //         string res_str = str1+str2;
        //         for(int i=0; i<len1; i++){
        //             cout << "i" << i << endl;
        //             overlap = true;
        //             for(int j=i; j<len1; j++){
        //                 if(str1[j]!=str2[j-i]){
        //                     overlap = false;
        //                     break;
        //                 }
        //             }
        //             if(overlap){

        //                 if(res<min(len1-i, len2)){
        //                     res_str = str1;
        //                     for(int k=len1-i; k<len2; k++){
        //                         res_str += str2[k];
        //                     }

        //                 }
        //             }
        //         }

        //         for(int i=0; i<len2; i++){
        //             overlap = true;
        //             for(int j=i; j<len2; j++){
        //                 if(str2[j]!=str1[j-i]){
        //                     overlap = false;
        //                     break;
        //                 }
        //             }
        //             if(overlap){
        //                 if(res<min(len2-i, len1)){
        //                     res_str = str2;
        //                     for(int k=len2-i; k<len1; k++){
        //                         res_str += str1[k];
        //                     }

        //                 }
        //             }
        //         }

        // //         }
        //         cout<< res;
        // return res_str;
    }
};