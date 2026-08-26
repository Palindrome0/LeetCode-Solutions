class Solution {
public:
    using ll = long long;

    const ll MOD = 1000000007;
    const ll BASE = 911382323;

    vector<ll> pref, power;

    // Hash of s[l ... r-1]
    ll getHash(int l, int r) {
        return (pref[r] - pref[l] * power[r - l] % MOD + MOD) % MOD;
    }

    // Returns true if s[l1 ... l1+len-1]
    // is lexicographically smaller than
    // s[l2 ... l2+len-1]
    bool smaller(string &s, int l1, int l2, int len) {

        int lo = 0, hi = len;

        // Find length of common prefix
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;

            if (getHash(l1, l1 + mid) ==
                getHash(l2, l2 + mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        int common = lo;

        // Completely equal
        if (common == len)
            return false;

        // First differing character determines lexicographical order
        return s[l1 + common] < s[l2 + common];
    }

    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        // ---------- Rolling hash preprocessing ----------

        pref.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            pref[i + 1] =
                (pref[i] * BASE + (s[i] - '0' + 1)) % MOD;

            power[i + 1] =
                power[i] * BASE % MOD;
        }

        // ---------- Sliding window ----------

        int i = 0;
        int count1 = 0;

        int bestLen = INT_MAX;
        int bestStart = -1;

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')
                count1++;

            // Too many 1s
            while (count1 > k) {
                if (s[i] == '1')
                    count1--;

                i++;
            }

            if (count1 == k) {

                // Remove unnecessary leading zeroes
                while (s[i] == '0')
                    i++;

                int len = j - i + 1;

                // Better because it is shorter
                if (len < bestLen) {
                    bestLen = len;
                    bestStart = i;
                }

                // Same length -> lexicographical comparison
                else if (len == bestLen) {

                    if (smaller(s, i, bestStart, len)) {
                        bestStart = i;
                    }
                }
            }
        }

        if (bestStart == -1)
            return "";

        return s.substr(bestStart, bestLen);
    }
};