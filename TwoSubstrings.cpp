#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[10000];
    cin >> s;
    int cnt;
    for (int i=0; i<strlen(s)-3; i++)
        if((s[i]=='A')&&(s[i+1]=='B')){
           for (int j=i+2; j<strlen(s); j++){
            if ((s[j]=='B')&&(s[j+1]=='A')){
                cout << "YES";
                return 0;
                }
           }
           break;
        }

    for (int i=0; i<strlen(s)-3; i++)
        if((s[i]=='B')&&(s[i+1]=='A')){
           for (int j=i+2; j<strlen(s); j++){
            if ((s[j]=='A')&&(s[j+1]=='B')){
                cout << "YES";
                return 0;
                }
           }
        break;
        }
    cout << "NO";
}
