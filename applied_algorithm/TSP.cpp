// #include <bits/stdc++.h>
// using namespace std;

// int E[20][20];
// int m, n, i, j, c;
// int vertices[20], n_vertices = 0, distances[20];
// bool isVertices[20];
// // int res = INT_MAX;

// bool isCandidate(int k, int c)
// {
//     return ((!isVertices[c]) && (E[k][vertices[n_vertices - 1]] > -1));
// }

// void Try(int k, int res)
// {
//     if (k >= n)
//     {
//         res = min(res, distances[n - 1]);
//     }
//     else
//     {
//         for (int l = 0; l < n; l++)
//         {
//             if ((!isCandidate(l))&&(distances[n_vertices]<res))
//             {   
//                 vertices[n_vertices] = l;
//                 distances[n_vertices] = distances[n_vertices - 1] + E[vertices[n_vertices - 1]][l];
//                 n_vertices++;
//                 k++;
//                 Try(k, res);
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     memset(E, -1, sizeof(E));

//     for (int t = 0; t < m; t++)
//     {
//         cin >> i >> j >> E[i][j];
//         E[j][i] = E[i][j];
//     }

//     cout << "\nDONE";
// }
