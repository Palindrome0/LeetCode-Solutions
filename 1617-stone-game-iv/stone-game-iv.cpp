class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,false);
        for(int x=1;x<=n;x++){
            for(int k=1;k*k<=x;k++){
                if(dp[x-k*k]==false){
                    dp[x]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};