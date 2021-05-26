#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class CombinationIterator
{
public:
    vector<string> v;
    int len, cnt = 0;
    CombinationIterator(string characters, int combinationLength)
    {
        // cout << endl;
        push(characters, combinationLength, 0, -1, "");
        sort(v.begin(), v.end());
        // for (auto x : v)
        // {
        //     cout << x << endl;
        // }

        len = v.size();
    }

    void permute(string &s, int l, int r)
    {
        if (l == r)
            v.push_back(s);

        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            permute(s, i + 1, r);
            swap(s[i], s[l]);
        }
    }

    void push(string &characters, int combinationLength, int k, int pos, string cur)
    {

        if (k == combinationLength)
        {
            // permute(cur, 0, k - 1);
            v.push_back(cur);
        }

        else
        {
            for (int i = pos + 1; i < characters.size(); i++)
            {
                push(characters, combinationLength, k + 1, i, cur + characters[i]);
            }
        }
    }
    string next()
    {
        return v[cnt++];
    }

    bool hasNext()
    {
        return cnt < len;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */