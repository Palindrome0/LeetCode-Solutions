class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            int low=0,high=col-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(grid[i][mid]<0)
                    high=mid-1;
                else
                    low=mid+1;
            }
            count+=col-low;
        }
        return count;
    }
};