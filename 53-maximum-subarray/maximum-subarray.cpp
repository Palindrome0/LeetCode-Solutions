class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            maxi=max(maxi, sum);
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
};