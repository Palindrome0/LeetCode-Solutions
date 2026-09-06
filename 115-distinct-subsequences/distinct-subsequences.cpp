class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>>dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=t.size();i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=min(i,(int)t.size());j++){
                unsigned long long take=0ll;
                if(s[i-1]==t[j-1])
                take=dp[i-1][j-1];
                unsigned long long nottake=dp[i-1][j];
                dp[i][j]=take+nottake;
            }
        }
        return dp[s.size()][t.size()];
    }
};