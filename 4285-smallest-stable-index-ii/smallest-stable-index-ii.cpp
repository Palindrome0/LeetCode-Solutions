class Solution {
public:
using ll=long long;
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll>maxi(n);
        vector<ll>mini(n);
        maxi[0]=nums[0];
        for(int i=1;i<n;i++)
        maxi[i]=max((ll)nums[i],maxi[i-1]);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        mini[i]=min((ll)nums[i],mini[i+1]);
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k)
            return i;
        }
        return -1;
    }
};