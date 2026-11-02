class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=0;
        if(n%2!=0)
        mid=nums[n/2];
        else mid=(int)((nums[n/2]+nums[n/2-1])/2);
        int ans=0;
        for(int x:nums)
        ans+=abs(mid-x);
        return ans;
    }
};