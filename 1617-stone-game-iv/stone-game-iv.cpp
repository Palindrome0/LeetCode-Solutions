class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for(int x = 1; x <= n; x++) {
            bool ans = false;
            for(int i = 1; i * i <= x; i++) {
                if(!dp[x - i * i]) {
                    ans = true;
                    break;
                }
            }
            dp[x] = ans;
        }
        return dp[n];
    }
};