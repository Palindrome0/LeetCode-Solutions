class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lar=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int x:nums)
        ans+=abs(x-lar);
        return ans;
    }
};