class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>prefixsum(n+1,0);
        for (int i=0;i<n;i++) {
            prefixsum[i+1]=prefixsum[i]+stones[i];
        }
        for (int i=n-2;i>=0;i--){
            for (int j=i+1;j<n;j++){
                int leftSum=prefixsum[j+1]-prefixsum[i+1];
                int rightSum=prefixsum[j]-prefixsum[i];
                dp[i][j]=max(leftSum-dp[i+1][j],rightSum-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};