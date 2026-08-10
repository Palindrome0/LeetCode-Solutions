class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // prefix[i] = sum of stoneValue[0 ... i-1]
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        /*
            dp[i][j] = maximum score Alice can obtain
                       from subarray [i ... j]

            leftBest[i][j] =
                max over k in [i+1 ... j]
                (prefix[k] + dp[i][k-1])

            rightBest[i][j] =
                max over k in [i ... j-1]
                (dp[k][j] - prefix[k])
        */
        vector<vector<int>> dp(n, vector<int>(n, 0));
        const int NEG = -1e9;
        vector<vector<int>> leftBest(n, vector<int>(n, NEG));
        vector<vector<int>> rightBest(n, vector<int>(n, NEG));
        // For a single element:
        // dp[i][i] = 0
        // rightBest[i][i] = dp[i][i] - prefix[i]
        for (int i = 0; i < n; i++) {
            rightBest[i][i] = -prefix[i];
        }
        /*
            Process by increasing right endpoint j.

            For fixed j, as i decreases, the split point where
            leftSum >= rightSum can only move left.

            Therefore we maintain p using a two-pointer technique.
        */
        for (int j = 1; j < n; j++) {
            // p = first split position where
            // leftSum >= rightSum.
            //
            // If no such position exists, p = j+1.
            int p = j + 1;
            for (int i = j - 1; i >= 0; i--) {
                int total = prefix[i] + prefix[j + 1];
                // Find first p such that:
                //
                // prefix[p] - prefix[i]
                // >=
                // prefix[j+1] - prefix[p]
                //
                // i.e.
                // 2 * prefix[p] >= prefix[i] + prefix[j+1]
                while (p > i + 1 &&
                       2 * prefix[p - 1] >= total) {
                    p--;
                }
                /*
                    For k < p:

                    leftSum < rightSum

                    Bob throws away right.
                    Alice keeps left.

                    Candidate:
                    leftSum + dp[i][k-1]

                    = prefix[k] - prefix[i] + dp[i][k-1]

                    leftBest stores:
                    prefix[k] + dp[i][k-1]
                */
                if (p > i + 1) {
                    dp[i][j] = max(
                        dp[i][j],
                        leftBest[i][p - 1] - prefix[i]
                    );
                }
                /*
                    No crossing point.

                    Every possible split has:
                    leftSum < rightSum

                    So Alice always keeps the left side.
                */
                if (p == j + 1) {

                    dp[i][j] = max(
                        dp[i][j],
                        leftBest[i][j - 1] - prefix[i]
                    );
                    // Also explicitly include k = j
                    dp[i][j] = max(
                        dp[i][j],
                        prefix[j] - prefix[i] + dp[i][j - 1]
                    );
                }
                /*
                    For k >= p:

                    leftSum >= rightSum

                    Bob throws away left.
                    Alice keeps right.

                    Candidate:
                    rightSum + dp[k][j]

                    = prefix[j+1] - prefix[k] + dp[k][j]

                    = prefix[j+1] +
                      (dp[k][j] - prefix[k])

                    rightBest stores:
                    dp[k][j] - prefix[k]
                */
                else {
                    dp[i][j] = max(
                        dp[i][j],
                        prefix[j + 1] + rightBest[p][j]
                    );
                    /*
                        If the sums are exactly equal,
                        Alice can choose either side.

                        The right-side candidate above is already
                        included, but we must ALSO consider the
                        left-side candidate.
                    */
                    if (2 * prefix[p] == total) {

                        dp[i][j] = max(
                            dp[i][j],
                            prefix[p] - prefix[i]
                            + dp[i][p - 1]
                        );
                    }
                }
                /*
                    Update leftBest.

                    Split k = j gives:

                    prefix[j] + dp[i][j-1]
                */
                leftBest[i][j] = max(
                    leftBest[i][j - 1],
                    prefix[j] + dp[i][j - 1]
                );
                /*
                    Update rightBest.

                    k = i gives:

                    dp[i][j] - prefix[i]
                */
                rightBest[i][j] = max(
                    rightBest[i + 1][j],
                    dp[i][j] - prefix[i]
                );
            }
        }
        return dp[0][n - 1];
    }
};