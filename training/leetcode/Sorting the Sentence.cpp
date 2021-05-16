#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string sortSentence(string s)
    {
        // Vector of string to save tokens
        vector<string> tokens;

        // stringstream class check1
        stringstream check1(s);

        string intermediate;

        // Tokenizing w.r.t. space ' '
        while (getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        int total = tokens.size();
        vector<string> res(total);
        for (auto t : tokens)
        {
            cout << t << "-> ";
            int i;
            for (i = 0; i < t.size(); i++)
            {
                if ((t[i] >= '0') && (t[i] <= '9'))
                    break;
            }
            int len = t.size();
            string t1 = t.substr(0, i);

            cout << t1 << ";" << t.substr(i, len - i) << endl;
            int idx = stoi(t.substr(i, len - i));
            res[idx - 1] = t1;
        }
        cout << endl;
        string result;
        for (auto x : res)
        {
            result += (x + " ");
        }
        result.pop_back();
        return result;
    }
};