class Solution {
public:
    const int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<array<int, 2>>> memo(m, vector<array<int, 2>>(n, {-2, -2}));
        function<int(int, int, int)> resolve = [&](int i, int j, int dir) -> int {
            if (i >= m || j >= n) return -1;
            if (memo[i][j][dir] != -2) return memo[i][j][dir];
            if (grid[i][j] == 0) {
                return memo[i][j][dir] = i * n + j;
            }
            if (dir == 0) {
                return memo[i][j][dir] = resolve(i + 1, j, 1);
            }
            return memo[i][j][dir] = resolve(i, j + 1, 0);
        };
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || dp[i][j] == 0) continue;
                int right = resolve(i, j + 1, 0);
                int down = resolve(i + 1, j, 1);
                if (right != -1) {
                    int x = right / n;
                    int y = right % n;
                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
                if (down != -1) {
                    int x = down / n;
                    int y = down % n;
                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};