class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1) {
                    s.insert(i * n + j);
                }
            }
        }
        vector<pair<int, int>> ones;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    ones.push_back({i, j});
                }
            }
        }
        int ans = 0;
        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                int overlap = 0;
                for (auto [x, y] : ones) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= n) {
                        continue;
                    }
                    int encoded = nx * n + ny;
                    if (s.count(encoded)) {
                        overlap++;
                    }
                }
                ans = max(ans, overlap);
            }
        }
        return ans;
    }
};