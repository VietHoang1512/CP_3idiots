class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        string res;
        int len1 = word1.size(), len2 = word2.size();
        int total = len1 + len2;
        int l = 0, r = 0;
        while (1)
        {
            if (l == len1)
            {
                for (int i = r; i < len2; i++)
                {
                    res += word2[i];
                }
                return res;
            }
            if (r == len2)
            {
                for (int i = l; i < len1; i++)
                {
                    res += word1[i];
                }
                return res;
            }
            if (word1[l] > word2[r])
            {
                res += word1[l];
                l++;
            }
            else if (word1[l] < word2[r])
            {
                res += word2[r];
                r++;
            }
            else
            {

                int tmp1 = l, tmp2 = r;
                char cur1 = word1[l], cur2 = word2[r];

                for (int i = l; i < len1; i++)
                {
                    if (word1[i] != cur1)
                    {
                        tmp1 = i;
                        cur1 = word1[i];
                        break;
                    }
                }

                for (int i = r; i < len2; i++)
                {
                    if (word2[i] != cur2)
                    {
                        tmp2 = i;
                        cur2 = word2[i];
                        break;
                    }
                }

                if (tmp1 - l < tmp2 - r)
                {
                    res += word1[l];
                    l++;
                    continue;
                }
                else if (tmp1 - l > tmp2 - r)
                {
                    res += word2[r];
                    r++;
                    continue;
                }
                else
                {
                    if (cur1 > cur2)
                    {
                        res += word1[l];
                        l++;
                        continue;
                    }
                    else
                    {
                        res += word2[r];
                        r++;
                        continue;
                    }
                }
                cout << "RESULT " << res << endl;
            }
        }
        return res;
    }
};