#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string greatestLetter(string s)
    {
        map<char, int> m, n;
        for (char c : s)
        {
            if (c >= 'a')
                m[c] = 1;
            else
                n[c - 'A' + 'a']++;
        }
        cout << "***\n\n";
        char c = 'z';
        while (c>='a')
        {
            if (m.count(c) || n.count(c)){
                char res = c+'a'-'A';
                string t;
                t += c;
                return t;
            }
                
            c--;
        }
        return "";
    }
};