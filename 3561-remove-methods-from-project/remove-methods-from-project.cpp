class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited,unordered_set<int>&group){
        visited[node]=1;
        group.insert(node);
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],adj,visited,group);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int>group;
        vector<bool>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto &p:invocations){
            adj[p[0]].push_back(p[1]);
        }
        dfs(k,adj,visited,group);
        for(int i=0;i<visited.size();i++){
            if(visited[i]) visited[i]=0;
        }
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i])
            st.push(i);
            while(!st.empty()){
                int node=st.top();
                st.pop();
                visited[node]=1;
                for(int i=0;i<adj[node].size();i++){
                    if(!group.contains(node)&&group.contains(adj[node][i])){
                        vector<int>vc(n);
                        iota(vc.begin(),vc.end(),0);
                        return vc;
                    }
                    else if(!visited[adj[node][i]]) st.push(adj[node][i]);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!group.contains(i)) ans.push_back(i);
        }
        return ans;
    }
};