class Solution {
public:

    vector<double> line(double x1, double y1, double x2, double y2){
//      Our assumption is that p1 p2 are not overlap
        double a = y2 - y1;
        double b = x1 - x2;
        double c = x1*(y1-y2) + y1*(x2-x1);
        if (a==0){
            return vector<double>({0, 1, c/b});
        }
        return vector<double>({1, b/a, c/a});
        
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        long long n_points = points.size();
        if (n_points==1) return 1;
        long long res = 0;
        
        for (long long i=0; i<n_points; i++){
            cout << (double)94911150/(double)94911151;
            cout << "Traversing on point " << points[i][0] << " " << points[i][1] << endl;
            map<vector<double>, long long> counter;
            long long overlap = 0;
            for(long long j=0; j<n_points; j++){
                
                double x1 = (double) points[i][0];
                double y1 = (double) points[i][1];
                double x2 = (double) points[j][0];
                double y2 = (double) points[j][1];
                
                if ((x1==x2)&&(y1==y2)){
                    overlap++;
                    cout << "Overlap++\n";
                    continue;
                }
                
                counter[line(x1, y1, x2, y2)]++;
                
            }
            counter[vector<double>({0., 0., 0.})] = 0;
            for (auto elem:counter){
                cout <<"key " << elem.first[0] << " " << elem.first[1] << " " << elem.first[2] << " value " << elem.second << endl;
                 res = max(res, overlap+elem.second);
                cout << "res " << res << endl;
            }
        }
        return res;
        
        
        
        
//         vector<vector<float>> dp;
//         vector<float> tmp;
//         int tmp_x, tmp_y;
//         for(int i=0; i<n_points; i++){
//             for (int j=0; j<n_points; j++){
//                 tmp_x = points[j][0] - points[i][0];
//                 tmp_y = points[j][1] - points[i][1];
//                 tmp = normalize((float)tmp_x, (float)tmp_y);
//                 // cout << i << " " << j << " " << tmp[0] << " "<< tmp[1] << endl;
//                 dp.push_back(tmp);
//             }
//         }
        
//         for(int i=0; i<dp.size(); i++){
//             cout << dp[i][0] << " " << dp[i][1] << endl;
//         }
        
        
        
        // return 0;
    }
    // vector<float> normalize(float x, float y){
    //     vector<float> tmp;
    //     if (x==0.0){
    //         tmp.push_back(0.0);
    //         if (y) tmp.push_back(1.0);
    //     }
    //     if (x!=0.0){
    //         tmp.push_back(1.0);
    //         tmp.push_back(y/x);
    //     }
    //         // cout << "*" << tmp[0] << "*" << tmp[1] << "*\n";
    //     return tmp;
    // }
};