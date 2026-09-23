class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total=0;
        for(int v:nums) total+=v;
        long long target=total-x;
        if(target<0) return -1;
        if(target==0) return nums.size();
        int l=0,best=-1;
        long long sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(l<=r&&sum>target){
                sum-=nums[l++];
            }
            if(sum==target)
                best=max(best,r-l+1);
        }
        return best==-1 ? -1 : nums.size()-best;
    }
};