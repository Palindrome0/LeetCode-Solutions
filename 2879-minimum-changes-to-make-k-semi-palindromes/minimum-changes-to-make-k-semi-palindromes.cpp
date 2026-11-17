class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for(int d = 1; d < len; d++) {
                    if(len % d != 0) continue;
                    int changes = 0;
                    for(int r = 0; r < d; r++) {
                        int l = i + r;
                        int h = j - (d - 1 - r);
                        int cnt = (len - r + d - 1) / d;
                        h = i + r + (cnt - 1) * d;
                        for(int x = 0; x < cnt / 2; x++) {
                            if(s[l + x * d] != s[h - x * d]) {
                                changes++;
                            }
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;
        for(int p = 1; p <= k; p++) {
            for(int i = 2 * p; i <= n; i++) {
                for(int j = 2 * (p - 1); j <= i - 2; j++) {
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};