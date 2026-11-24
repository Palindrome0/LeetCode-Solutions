class Solution {
public:
    int maxLength(vector<int>& nums) {
        int leni=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int g=nums[i],l=nums[i];
            int len=INT_MIN;
            unsigned long long prod=nums[i];
            for(int j=i+1;j<nums.size();j++){
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                prod=prod*nums[j];
                len=j-i+1;
                if(prod==l*g)
                leni=max(leni,len);
            }
        }
        return leni;
    }
};