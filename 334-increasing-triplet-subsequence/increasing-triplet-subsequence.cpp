class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return false;
        vector<int>smallest(n),largest(n);
        smallest[0]=nums[0];
        largest[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        smallest[i]=min(smallest[i-1],nums[i]);
        for(int j=n-2;j>=0;j--)
        largest[j]=max(largest[j+1],nums[j]);
        for(int i=1;i<n-1;i++){
            if(smallest[i-1]<nums[i]&&nums[i]<largest[i+1])
            return true;
        }
        return false;
    }
};