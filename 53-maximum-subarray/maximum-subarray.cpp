class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN,i=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
            while(sum<0)
            sum-=nums[i],i++;
        }
        return maxi;
    }
};