class Solution {
public:
    static int digitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    static bool cmp(int a,int b){
        int sum1=digitSum(a);
        int sum2=digitSum(b);
        if(sum1!=sum2) 
        return sum1<sum2;
        return a<b;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>vec=nums;
        unordered_map<int,int>mp;
        vector<bool>visited(nums.size(),false);
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();i++)
        mp[vec[i]]=i;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(visited[i]||mp[nums[i]]==i) 
            continue;
            int j=i;
            int len=0;
            while(!visited[j]){
                visited[j]=true;
                j=mp[nums[j]];
                len++;
            }
            count+=len-1;
        }
        return count;
    }
};