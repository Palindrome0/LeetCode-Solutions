class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),0));
        for(int i=0;i<piles.size();i++){
            dp[i][i]=piles[i];
        }
        for(int i=piles.size()-1;i>=0;i--){
            for(int j=0;j<piles.size();j++){
                if(i>j) continue;
                if(i==piles.size()-1) {dp[i][j]=piles[j]-dp[i][j-1]; continue;}
                if(j==0) {dp[i][j]=piles[i]-dp[i+1][j]; continue;}
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][piles.size()-1]>0;
    }
};