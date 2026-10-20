class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n + 1, 0);
        for (int i = 0; i < n; i++) 
        prefMax[i + 1] = max(prefMax[i], nums[i]);
        for (int i = n - 1; i >= 0; i--) 
        suffMin[i] = min(suffMin[i + 1], nums[i]);
        for (int i = 0; i < n - 1; i++)
        prefDrop[i + 1] = prefDrop[i] + (nums[i] > nums[i + 1]);
        prefDrop[n] = prefDrop[n - 1];
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            for (int i = 0; i < n; i += k) {
                int r = i + k - 1;
                int drops = prefDrop[r] - prefDrop[i];
                if (nums[r] > nums[i]) drops++;
                if (drops > 1 || prefMax[i] > suffMin[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans += k;
        }
        return ans;
    }
};