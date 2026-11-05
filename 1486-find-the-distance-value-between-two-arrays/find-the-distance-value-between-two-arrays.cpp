class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr2.size();
        sort(arr2.begin(),arr2.end());
        int count=0;
        for(int x:arr1){
            auto it=lower_bound(arr2.begin(),arr2.end(),x-d);
            if(it==arr2.end()||*it>x+d)
            count++;
        }
        return count;
    }
};