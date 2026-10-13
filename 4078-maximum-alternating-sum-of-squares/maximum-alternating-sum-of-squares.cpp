class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        long long sum=0ll;
        for(int i=0;i<n;i++)
        pq.push(abs(nums[i]));
        if(n%2==0){
            for(int i=1;i<=n/2;i++){
            sum+=(pq.top()*pq.top());
            pq.pop();
            }
            while(!pq.empty()){
            sum-=(pq.top()*pq.top());
            pq.pop();
            }
            return sum;
        }
        else{
            for(int i=1;i<=(n/2+1);i++){
            sum+=(pq.top()*pq.top());
            pq.pop();
            }
            while(!pq.empty()){
            sum-=(pq.top()*pq.top());
            pq.pop();
            }
            return sum;
        }
    }
};