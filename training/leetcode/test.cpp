class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int total = words.size(), res = 0;
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = i + 1; j < total; j++)
            {
                if (words[i][0] == words[j][1])
                    if (words[i][1] == words[j][0])
                        res++;
            }
        }
        return res;
    }
};