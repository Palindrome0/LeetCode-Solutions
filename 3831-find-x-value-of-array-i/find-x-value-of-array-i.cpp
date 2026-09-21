class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k),dp(k);
        for(long long x:nums){
            vector<long long> ndp(k);
            int v=x%k;
            ndp[v]++;
            for(int r=0;r<k;r++)
                ndp[(r*v)%k]+=dp[r];
            for(int r=0;r<k;r++){
                ans[r]+=ndp[r];
                dp[r]=ndp[r];
            }
        }
        return ans;
    }
};