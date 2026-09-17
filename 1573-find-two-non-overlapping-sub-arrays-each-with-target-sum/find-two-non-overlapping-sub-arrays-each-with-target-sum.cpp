class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        int l = 0;
        long long sum = 0;
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l];
                l++;
            }
            if (r > 0)
                best[r] = best[r - 1];
            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && best[l - 1] != INT_MAX) {
                    ans = min(ans, len + best[l - 1]);
                }
                best[r] = min(best[r], len);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};