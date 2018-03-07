class Solution {
public:
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    // build the grid where each entry is the maximum length of the plus sign
    vector<vector<int>> grid(N, vector<int>(N, N));
    for (auto& m : mines) {grid[m[0]][m[1]] = 0;}
    // consider i as moving along the diagonal, for each locatoin check its plus sign
    for (int i = 0; i < N; i++) {
        for (int j = 0, k = N - 1, l = 0, r = 0, u = 0, d = 0; j < N; j++, k--) {
            // ith row
            grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
            grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
            // ith column
            grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
            grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
        }
    }
    // find the maximum
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, grid[i][j]);
        }
    }
    return res;
    }
};