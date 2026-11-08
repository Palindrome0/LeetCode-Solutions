class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int>cols;
        unordered_map<int,int>rows;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    cols[j]++;
                    rows[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(cols[j]>1||rows[i]>1)
                    ans++;
                }
            }
        }
        return ans;
    }
};