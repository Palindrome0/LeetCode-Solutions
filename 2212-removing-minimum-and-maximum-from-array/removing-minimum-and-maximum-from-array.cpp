class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        int posm=-1,posma=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                posm=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                posma=i;
            }
        }
        int a=min(posm,posma)+1;
        int b=max(posm,posma)+1;
        return min({b,(int)nums.size()-a+1,a+(int)nums.size()-b+1});
    }
};