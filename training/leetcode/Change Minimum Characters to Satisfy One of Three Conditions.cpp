class Solution
{
public:
    int minCharacters(string a, string b)
    {
        vector<int> va, vb;
        int dpa[1005], dpb[1005];
        memset(dpa, 0, sizeof(dpa));
        memset(dpb, 0, sizeof(dpb));

        int minv = 'a' - '0' - 48, maxv = 'z' - '0' - 48;
        cout << minv << " " << maxv << endl;
        int mina = maxv, minb = maxv, maxa = minv, maxb = minv;
        int maxa_appear = 0;
        for (auto c : a)
        {
            int tmp = c - '0' - 48;
            va.push_back(tmp);
            dpa[tmp]++;
            maxa_appear = max(maxa_appear, dpa[tmp]);
            maxa = max(maxa, tmp);
            mina = min(mina, tmp);
        }
        int maxb_appear = 0;
        for (auto c : b)
        {
            int tmp = c - '0' - 48;
            vb.push_back(tmp);
            dpb[tmp]++;
            maxb_appear = max(maxb_appear, dpb[tmp]);
            maxb = max(maxb, tmp);
            minb = min(minb, tmp);
        }
        int lena = va.size(), lenb = vb.size();
        int res = 0;

        int tmp0 = (lena - maxa_appear) + (lenb - maxb_appear);

        int tmp1 = 0;
        cout << "\nA\n";
        if (minb != minv)
        {
            // tmp1 = 0;

            for (auto x : va)
            {
                cout << x << " ";
                tmp1 += (x >= minb);
            }
        }
        else
        {
            tmp1 = dpb[minb];
            minb = minb +
        }
        cout << "\nB\n";
        int tmp2 = INT_MAX;
        if (mina != minv)
        {
            tmp2 = 0;
            for (auto x : vb)
            {
                cout << x << " ";
                tmp2 += (x >= mina);
            }
        }
        cout << tmp0 << " " << tmp1 << " " << tmp2 << endl;
        return min(min(tmp0, tmp1), tmp2);
    }
};