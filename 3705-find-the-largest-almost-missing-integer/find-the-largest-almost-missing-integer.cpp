class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int first=nums[0];
        int n=nums.size();
        int last=nums[n-1];
        int ans=*max_element(nums.begin(),nums.end());
        if(k==1){
            vector<int>freq(51,0);
            for(int i=0;i<n;i++){
                freq[nums[i]]++;
            }
            for(int i=freq.size()-1;i>=0;i--){
                if(freq[i]==1)
                return i;
            }
            return -1;
        }
        if(k==n){
            return ans;
        }
        int countfirst=0;
        int countlast=0;
        if(first==last) return -1;
        for(int i=0;i<n;i++){
            if(nums[i]==first)
            countfirst++;
            if(nums[i]==last)
            countlast++;
        }
        if(countfirst==1&&countlast==1)
        return max(first,last);
        else if(countfirst==1)
        return first;
        else if(countlast==1)
        return last;
        else return -1;
    }
};