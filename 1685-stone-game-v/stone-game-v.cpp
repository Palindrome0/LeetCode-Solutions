class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int total = prefix[j + 1] - prefix[i];
                int left = 0;
                for (int k = i + 1; k <= j; k++) {
                    left = prefix[k] - prefix[i];
                    int right = total - left;
                    if (left < right) {
                        dp[i][j] = max(dp[i][j],left + dp[i][k - 1]);
                    }
                    else if (left > right) {
                        dp[i][j] = max(dp[i][j],right + dp[k][j]);
                    }
                    else {
                        dp[i][j] = max(dp[i][j],max(left + dp[i][k - 1],right + dp[k][j])
                        );
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};