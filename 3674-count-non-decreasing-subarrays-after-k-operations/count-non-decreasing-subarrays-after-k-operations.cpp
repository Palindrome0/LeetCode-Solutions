class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 18;
        vector<int> nxt(n, n);
        vector<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();
            if(!st.empty())
                nxt[i] = st.back();
            st.push_back(i);
        }
        vector<vector<int>> up(n + 1, vector<int>(LOG, n));
        vector<vector<long long>> sum(n + 1, vector<long long>(LOG, 0));
        for(int i = 0; i < n; i++) {
            up[i][0] = nxt[i];
            sum[i][0] = 1LL * nums[i] * (nxt[i] - i);
        }
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                int mid = up[i][j - 1];
                up[i][j] = up[mid][j - 1];
                sum[i][j] = sum[i][j - 1] + sum[mid][j - 1];
            }
        }
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];
        auto getCost = [&](int l, int r) -> long long {
            long long total = 0;
            int pos = l;
            for(int j = LOG - 1; j >= 0; j--) {
                if(up[pos][j] <= r) {
                    total += sum[pos][j];
                    pos = up[pos][j];
                }
            }
            total += 1LL * nums[pos] * (r - pos + 1);
            return total - (pref[r + 1] - pref[l]);
        };
        long long ans = 0;
        for(int r = 0; r < n; r++) {
            int low = 0, high = r;
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(getCost(mid, r) <= k)
                    high = mid;
                else
                    low = mid + 1;
            }
            ans += r - low + 1;
        }
        return ans;
    }
};