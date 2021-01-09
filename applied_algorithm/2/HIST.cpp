// #include <bits/stdc++.h>
// using namespace std;

// const long long mx = 1e6;

// long long n, t = 0;
// long long A[mx];
// long long cur_tower = 0, top_id;
// long long height;
// long long maxArea;

// long long main()
// {
//     while (1)
//     {

//         cin >> n;
//         if (!n)
//             break;
//         vector<long long> h(n + 2), l(n + 1), r(n + 1);
//         stack<long long> s;
//         s.push(0);
//         // cout << "*** On test " << ++t << " ***" << endl;
//         // cout << "S" << s.size() << endl;
//         // cout << "Left" << l.size() << endl;
//         // cout << "Right" << r.size() << endl;

//         h[0] = -1;
//         h[n + 1] = -1;

//         for (long long i = 0; i < n; i++)
//         {
//             cin >> h[i + 1];
//         }

//         for (long long i = 1; i <= n; i++)
//         {
//             if (h[i] > h[s.top()])
//             {
//                 l[i] = s.top();
//             }
//             else
//             {
//                 while (h[i] <= h[s.top()])
//                 {
//                     s.pop();
//                 }
//                 l[i] = s.top();
//             }

//             s.push(i);
//         }
//         while (!s.empty())
//         {
//             s.pop();
//         }
//         s.push(n + 1);

//         for (long long i = n; i >= 1; i--)
//         {
//             if (h[i] > h[s.top()])
//             {
//                 r[i] = s.top();
//             }
//             else
//             {
//                 while (h[i] <= h[s.top()])
//                 {
//                     s.pop();
//                 }
//                 r[i] = s.top();
//             }

//             s.push(i);
//         }
//         maxArea = 0;
//         for (long long i = 1; i < n + 1; i++)
//         {
//             maxArea = max(maxArea, (r[i] - l[i] - 1) * h[i]);
//         }
//         cout << maxArea << endl;

//         //     cur_tower = 0;
//         //     maxArea = 0;
//         //     stack<long long> s;
//         //     for (long long cur_tower = 0; cur_tower < n; cur_tower++)
//         //     {
//         //         // cout << "____________________\n";
//         //         // cout << "Current " << cur_tower << " max area " << maxArea << endl;
//         //         // if (!s.empty())
//         //         //     cout << "Top " << s.top() << endl;

//         //         if ((s.empty()) || (A[s.top()] <= A[cur_tower]))
//         //         {
//         //             s.push(cur_tower);
//         //             // cout << "Pushed: " << cur_tower << " value: " << A[cur_tower] << endl;
//         //         }
//         //         else
//         //         {
//         //             top_id = s.top();
//         //             height = A[top_id];
//         //             while (A[top_id] > A[cur_tower])
//         //             {
//         //                 // cout << "Poped " << s.top() << " value: " << A[s.top()] << endl;
//         //                 s.pop();
//         //                 if (!s.empty())
//         //                     maxArea = max(maxArea, height * (cur_tower - top_id));
//         //                 else
//         //                     maxArea = max(maxArea, height * cur_tower);
//         //                 if (s.empty())
//         //                     break;
//         //                 top_id = s.top();
//         //                 height = A[top_id];
//         //             }
//         //             s.push(cur_tower);
//         //         }
//         //     }
//         //     // cout << "RESULT\n";
//         //     // cout << maxArea << endl;
//         //     // cout << "Pop stack only\n";

//         //     // for(long long i=0; i<s.size(); i++) cout << s[i] << " ";
//         //     while (!s.empty())
//         //     {
//         //         top_id = s.top();
//         //         height = A[top_id];
//         //         // cout << "Poped " << s.top() << " value: " << A[s.top()] << endl;
//         //         s.pop();
//         //         if (!s.empty())
//         //             maxArea = max(maxArea, height * (n - top_id - 2));
//         //         else
//         //             maxArea = max(maxArea, height * (n-1));
//         //     }
//         //     // cout << "RESULT\n";
//         //     cout << maxArea << endl;
//         // }

//     }
//     // return 0;
// }

// C++ program to find maximum rectangular area in
// linear time
#include <bits/stdc++.h>
using namespace std;

// The main function to find the maximum rectangular
// area under given histogram with n bars
long long getMaxArea(long long hist[], long long n)
{
    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<long long> s;

    long long max_area = 0;  // Initialize max area
    long long tp;            // To store top of stack
    long long area_with_top; // To store area with top bar
                       // as the smallest bar

    // Run through all bars of given histogram
    long long i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else
        {
            tp = s.top(); // store the top index
            s.pop();      // pop the top

            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
long long hist[1000005];
// Driver program to test above function
int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        memset(hist, 0, sizeof(hist));

        for (long long j = 0; j < n; j++)
        {
            cin >> hist[j];
        }
        cout << getMaxArea(hist, n) << endl;
    }

    return 0;
}