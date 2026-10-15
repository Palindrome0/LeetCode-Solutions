class Solution {
public:
    int count(vector<int>& nums,int len){
        int n=nums.size();
        unordered_set<int>st;
        int i=0,j=0;
        int sum=0;
        unordered_map<int,int>mp;
        while(j-i+1<len){
            st.insert(nums[j]);
            mp[nums[j]]++;
            j++;
        }
        for(;j<n;j++){
            st.insert(nums[j]);
            mp[nums[j]]++;
            sum+=st.size()*st.size();
            if(--mp[nums[i]]==0)
            st.erase(nums[i]);
            i++;
        }
        return sum;
    }
    int sumCounts(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        sum+=count(nums,i);
        return sum;
    }
};