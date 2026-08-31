class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int target = coin; target <= amount; target++) {
                if (dp[target] > INT_MAX - dp[target - coin])
                    dp[target] = INT_MAX;
                else
                    dp[target] += dp[target - coin];
            }
        }
        return dp[amount];
    }
};