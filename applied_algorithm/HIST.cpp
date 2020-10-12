#include <bits/stdc++.h>
using namespace std;

const long long mx = 1e6;

long long n, t = 0;
long long A[mx];
long long cur_tower = 0, top_id;
long long height;
long long maxArea;

int main()
{
    while (1)
    {
        
        cin >> n;
        if (!n)
            break;
        vector<long long> h(n + 2), l(n + 1), r(n + 1);
        stack<long long> s;
        s.push(0);
        // cout << "*** On test " << ++t << " ***" << endl;
        // cout << "S" << s.size() << endl;
        // cout << "Left" << l.size() << endl;
        // cout << "Right" << r.size() << endl;

        h[0] = -1;
        h[n + 1] = -1;

        for (long long i = 0; i < n; i++)
        {
            cin >> h[i + 1];
        }

        for (long long i = 1; i <= n; i++)
        {
            if (h[i] > h[s.top()])
            {
                l[i] = s.top();
            }
            else
            {
                while (h[i] <= h[s.top()])
                {
                    s.pop();
                }
                l[i] = s.top();
            }

            s.push(i);
        }
        while (!s.empty())
        {
            s.pop();
        }
        s.push(n + 1);


        for (long long i = n; i >= 1; i--)
        {
            if (h[i] > h[s.top()])
            {
                r[i] = s.top();
            }
            else
            {
                while (h[i] <= h[s.top()])
                {
                    s.pop();
                }
                r[i] = s.top();
            }

            s.push(i);
        }
        maxArea = 0;
        for (long long i = 1; i < n + 1; i++)
        {
            maxArea = max(maxArea, (r[i] - l[i] - 1) * h[i]);
        }
        cout << maxArea << endl;

        //     cur_tower = 0;
        //     maxArea = 0;
        //     stack<long long> s;
        //     for (long long cur_tower = 0; cur_tower < n; cur_tower++)
        //     {
        //         // cout << "____________________\n";
        //         // cout << "Current " << cur_tower << " max area " << maxArea << endl;
        //         // if (!s.empty())
        //         //     cout << "Top " << s.top() << endl;

        //         if ((s.empty()) || (A[s.top()] <= A[cur_tower]))
        //         {
        //             s.push(cur_tower);
        //             // cout << "Pushed: " << cur_tower << " value: " << A[cur_tower] << endl;
        //         }
        //         else
        //         {
        //             top_id = s.top();
        //             height = A[top_id];
        //             while (A[top_id] > A[cur_tower])
        //             {
        //                 // cout << "Poped " << s.top() << " value: " << A[s.top()] << endl;
        //                 s.pop();
        //                 if (!s.empty())
        //                     maxArea = max(maxArea, height * (cur_tower - top_id));
        //                 else
        //                     maxArea = max(maxArea, height * cur_tower);
        //                 if (s.empty())
        //                     break;
        //                 top_id = s.top();
        //                 height = A[top_id];
        //             }
        //             s.push(cur_tower);
        //         }
        //     }
        //     // cout << "RESULT\n";
        //     // cout << maxArea << endl;
        //     // cout << "Pop stack only\n";

        //     // for(long long i=0; i<s.size(); i++) cout << s[i] << " ";
        //     while (!s.empty())
        //     {
        //         top_id = s.top();
        //         height = A[top_id];
        //         // cout << "Poped " << s.top() << " value: " << A[s.top()] << endl;
        //         s.pop();
        //         if (!s.empty())
        //             maxArea = max(maxArea, height * (n - top_id - 2));
        //         else
        //             maxArea = max(maxArea, height * (n-1));
        //     }
        //     // cout << "RESULT\n";
        //     cout << maxArea << endl;
        // }

        
    }
    // return 0;
}