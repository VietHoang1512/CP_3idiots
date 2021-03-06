#include <bits/stdc++.h>

using namespace std;
const int mx = 500005;
int emails[mx], phones[mx], orders[mx];
vector<int> groups;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("D:/VH/CP_3idiots/final_exam/4/cpp/INP.TXT", "r", stdin);
    freopen("D:/VH/CP_3idiots/final_exam/4/cpp/OUT.TXT", "w", stdout);
    for (int i = 0; i <500000; i++)
    {
        cin >> emails[i]; 
        groups.push_back(i);
    }
    for (int i = 0; i <500000; i++)
    {
        cin >> phones[i];  
    }
    
    for (int i = 0; i <500000; i++)
    {
        cin >> orders[i];  
    }
    for(int i=1; i+1<500000; i++){
        for(int j=i+1; j<500000; j++){
            int tmp = min(groups[i], groups[j]);
            if ((emails[i] == emails[j])&&(emails[i])){
                groups[j] = tmp;
                groups[i] = tmp;             
            }
            if ((phones[i] == phones[j])&&(phones[i])){
                groups[j] = tmp;
                groups[i] = tmp;             
            }
            if ((orders[i] == orders[j])&&(orders[i])){
                groups[j] = tmp;
                groups[i] = tmp;             
            }
        }
    }

    for (int i = 0; i <500000; i++)
    {
        cout << groups[i];  
    }


}
