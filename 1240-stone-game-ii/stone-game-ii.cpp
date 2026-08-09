class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // suffix[i] = sum of piles[i ... n-1]
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        // dp[i][M] = maximum stones current player can get
        // starting from i with current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                // Can take everything
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                    continue;
                }
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int nextM = max(M, X);
                    int currentScore =
                        suffix[i] - dp[i + X][nextM];
                    dp[i][M] = max(dp[i][M], currentScore);
                }
            }
        }
        return dp[0][1];
    }
};