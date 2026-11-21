class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;
    vector<int> last;
    vector<int> newParent;
    void dfs1(int u, vector<vector<int>>& tree, string& s) {
        int c = s[u] - 'a';
        int prev = last[c];
        if (u != 0 && prev != -1) {
            newParent[u] = prev;
        }
        last[c] = u;
        for (int v : tree[u]) {
            dfs1(v, tree, s);
        }
        last[c] = prev;
    }
    int dfs2(int u) {
        int sz = 1;
        for (int v : adj[u]) {
            sz += dfs2(v);
        }
        answer[u] = sz;
        return sz;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        adj.resize(n);
        answer.resize(n);
        last.assign(26, -1);
        newParent = parent;
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
        dfs1(0, tree, s);
        for (int i = 1; i < n; i++) {
            adj[newParent[i]].push_back(i);
        }
        dfs2(0);
        return answer;
    }
};