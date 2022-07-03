#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class TextEditor
{
public:
    string res = "";
    int loc = 0;
    TextEditor()
    {

    }

    void addText(string text)
    {
        res.insert(loc, text);
        loc += text.size();
        // cout << "addtext: " << res << endl;
    }

    int deleteText(int k)
    {
        int len_substr = min(k, loc);
        res.erase(res.begin() + loc - len_substr, res.begin() + loc);
        loc -= len_substr;
        // cout << "delete text: " << res << endl;
        return len_substr;
    }

    string cursorLeft(int k)
    {
        loc = max(0, loc - k);
        if (loc>=10){
            // cout << "cursor left: " << res.substr(loc-10, 10) << endl;
            return res.substr(loc-10, 10);

        }
        // cout << "cursor left: " << res.substr(0, loc) << endl;
        return res.substr(0, loc);
    }

    string cursorRight(int k)
    {
        int len = res.size();
        loc = min(len, loc + k);
        if (loc>=10){
            // cout << "cursor right: " << res.substr(loc-10, 10) << endl;
            return res.substr(loc-10, 10);

        }
        // cout << "cursor right: " << res.substr(0, loc) << endl;
        return res.substr(0, loc);
    }
};