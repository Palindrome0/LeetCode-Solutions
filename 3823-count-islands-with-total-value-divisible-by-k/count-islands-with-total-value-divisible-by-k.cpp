class Solution {
public:
    vector<int>x={1,-1,0,0};
    vector<int>y={0,0,1,-1};
    long long bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,long long sum){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            sum+=grid[r][c];
            visited[r][c]=true;
            for(int i=0;i<4;i++){
                int row=r+x[i];
                int col=c+y[i];
                if(row>=0&&row<grid.size()&&col>=0&&col<grid[0].size()&&grid[row][col]>0&&!visited[row][col]){
                q.push({row,col});
                visited[row][col]=true;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        vector<long long>islands;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]>0)
                islands.push_back(bfs(i,j,grid,visited,0ll));
            }
        }
        for(auto x:islands){
        if(x%k==0)
        count++;
        }
        return count;
    }
};