class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>>dp(stoneValue.size(),vector<int>(stoneValue.size(),0));
        for(int i=stoneValue.size()-1;i>=0;i--){
            for(int j=0;j<stoneValue.size();j++){
                if(i>j) continue;
                long long sum=0LL;
                for(int k=i;k<=j;k++) sum+=stoneValue[k];
                int left=0;
                for(int k=i+1;k<=j;k++){
                    left+=stoneValue[k-1];
                    int right=sum-left;
                    if(left>right){
                        dp[i][j]=max(dp[i][j],max(dp[i][j],right+dp[k][j]));
                    }
                    else if(left<right){
                        dp[i][j]=max(dp[i][j],max(dp[i][j],left+dp[i][k-1]));
                    }
                    else{
                        dp[i][j]=max(dp[i][j],max(right+dp[k][j],left+dp[i][k-1]));
                    }
                }
            }
        }
        return dp[0][stoneValue.size()-1];
    }
};