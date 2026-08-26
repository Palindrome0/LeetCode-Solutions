class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<long long,int>mp;
        for(long long x:nums){
            mp[x]++;
            if(mp[x]==2)
            return true;
        }
        return false;
    }
};