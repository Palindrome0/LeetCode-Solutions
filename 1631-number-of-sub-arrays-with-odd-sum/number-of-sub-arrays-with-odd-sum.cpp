class Solution {
public:
    const long long MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        unordered_set<int>even;
        unordered_set<int>odd;
        vector<int>prefix(arr.size());
        prefix[0]=arr[0];
        int ans=0;
        if(arr[0]%2!=0)
        ans++,odd.insert(arr[0]);
        else even.insert(arr[0]);
        for(int i=1;i<arr.size();i++){
            prefix[i]=arr[i]+prefix[i-1];
            if(prefix[i]%2==0){
                ans=(int)(ans+odd.size())%MOD;
                even.insert(prefix[i]);
            }
            else{
                ans=(int)(ans+even.size()+1)%MOD;
                odd.insert(prefix[i]);
            }
        }
        return ans;
    }
};