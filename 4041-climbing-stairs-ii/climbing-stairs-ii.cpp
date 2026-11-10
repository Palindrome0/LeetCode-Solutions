class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<=n&&j<=i+3){
                dp[j]=min(costs[j-1]+((j-i)*(j-i))+dp[i],dp[j]);
                j++;
            }
        }
        return dp[n];
    }
};