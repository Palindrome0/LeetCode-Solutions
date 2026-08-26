class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<int> p;

        // Positions of all 1s
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                p.push_back(i);
        }

        if (p.size() < k)
            return "";

        // --------------------------------------------------
        // Step 1: Find minimum possible length
        // --------------------------------------------------

        int bestLen = INT_MAX;

        for (int i = 0; i + k - 1 < p.size(); i++) {
            int len = p[i + k - 1] - p[i] + 1;
            bestLen = min(bestLen, len);
        }

        // --------------------------------------------------
        // Step 2: Find lexicographically smallest candidate
        // --------------------------------------------------

        vector<int> candidates;

        for (int i = 0; i + k - 1 < p.size(); i++) {
            if (p[i + k - 1] - p[i] + 1 == bestLen)
                candidates.push_back(p[i]);
        }

        // Only one candidate
        if (candidates.size() == 1)
            return s.substr(candidates[0], bestLen);

        /*
            All candidates have the same length.

            We need the lexicographically smallest substring.

            Find the minimum suffix among the candidate starting
            positions using pairwise elimination.

            Since all candidates have the same length, comparing
            their suffixes is equivalent to comparing the candidate
            substrings.
        */

        int best = candidates[0];

        for (int idx = 1; idx < candidates.size(); idx++) {

            int cur = candidates[idx];

            int a = best;
            int b = cur;

            while (a < best + bestLen &&
                   b < cur + bestLen &&
                   s[a] == s[b]) {
                a++;
                b++;
            }

            // If cur is lexicographically smaller
            if (a < best + bestLen &&
                b < cur + bestLen &&
                s[b] < s[a]) {
                best = cur;
            }
        }

        return s.substr(best, bestLen);
    }
};