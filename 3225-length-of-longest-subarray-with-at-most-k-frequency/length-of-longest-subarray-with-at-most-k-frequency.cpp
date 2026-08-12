class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        unordered_map<int,int>mp;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};