#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> reachable(m, vector<int>(n, 0));
        int res = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            DFS(i, 0, reachable, grid, res);
        }
        return res;
    }
    int DFS(int x, int y, vector<vector<int>> &reachable, vector<vector<int>> &grid, int &res)
    {

        int m = reachable.size(), n = reachable[0].size();
        if(x<0||y<0||x>m-1||y>n-1) return 0;
        if (reachable[x][y])
            return 0;
        reachable[x][y] = 1;
        res = max(res, y);

        if (y == n-1)
        {
            return 0;
        }
        if (grid[x][y + 1] > grid[x][y])
            DFS(x, y + 1, reachable, grid, res);
        if (x > 0)
        {
            if (grid[x - 1][y + 1] > grid[x][y])
                DFS(x - 1, y + 1, reachable, grid, res);
        }
        if (x < n - 1)
        {
            if (grid[x + 1][y + 1] > grid[x][y])
                DFS(x + 1, y + 1, reachable, grid, res);
        }

        return 0;
    }
};

[ [ 1000000, 92910, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068 ], [ 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118 ] ]