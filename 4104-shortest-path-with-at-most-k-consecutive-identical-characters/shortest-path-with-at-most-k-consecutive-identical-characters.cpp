class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        using T = tuple<long long, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        pq.push({0, 0, 1, labels[0] - 'a'});
        while (!pq.empty()) {
            auto [cost, u, len, ch] = pq.top();
            pq.pop();
            if (u == n - 1) return cost;
            if (cost > dist[u][len]) continue;
            for (auto [v, w] : adj[u]) {
                int nextLen = (labels[v] - 'a' == ch) ? len + 1 : 1;
                if (nextLen > k) continue;
                if (cost + w < dist[v][nextLen]) {
                    dist[v][nextLen] = cost + w;
                    pq.push({cost + w, v, nextLen, labels[v] - 'a'});
                }
            }
        }
        return -1;
    }
};