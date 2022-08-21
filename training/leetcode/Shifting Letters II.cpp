#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int len = s.size(), total = shifts.size();
        vector<int> inc(len, 0), dec(len, 0);
        for (auto shift : shifts)
        {
            if (shift[2] == 1)
            {
                inc[shift[1]]++;
                if (shift[0] >= 1)
                    dec[shift[0] - 1]++;
            }
            else
            {
                dec[shift[1]]++;
                if (shift[0] >= 1)
                    inc[shift[0] - 1]++;
            }
        }
        cout << "\nINC\n";
        for (auto x : inc)
        {
            cout << x << " ";
        }
        cout << "\nDEC\n";
        for (auto x : dec)
        {
            cout << x << " ";
        }
        cout << "\n";
        vector<int> inc2(len, 0), dec2(len, 0);
        inc2[len - 1] = inc[len - 1];
        dec2[len - 1] = dec[len - 1];
        for (int i = len - 2; i >= 0; i--)

        {
            inc2[i] = inc[i] + inc2[i + 1];
            dec2[i] = dec[i] + dec2[i + 1];
        }
        cout << "\nINC2\n";
        for (auto x : inc2)
        {
            cout << x << " ";
        }
        cout << "\nDEC2\n";
        for (auto x : dec2)
        {
            cout << x << " ";
        }
        cout << "\n";
        for (int i = 0; i < len; i++)
        {
            int res = (inc2[i] - dec2[i]) % 26;
            cout << (s[i] - 'a' + res + 26) % 26 << " ";
            s[i] = (s[i] - 'a' + res + 26) % 26 + 'a';
        }
        cout << "\n***\n";
        return s;
    }
};