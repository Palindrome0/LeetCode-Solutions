class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        long long sum=0ll;
        for(int i=0;i<n;i++)
        pq.push(abs(nums[i]));
        n=(n%2==0)?n/2:n/2+1;
        for(int i=1;i<=n;i++){
            sum+=(pq.top()*pq.top());
            pq.pop();
        }
        while(!pq.empty()){
            sum-=(pq.top()*pq.top());
            pq.pop();
        }
        return sum;
    }
};