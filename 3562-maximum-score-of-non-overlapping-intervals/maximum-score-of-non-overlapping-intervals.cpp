#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };
    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return lexicographical_compare(
            a.ids.begin(), a.ids.end(),
            b.ids.begin(), b.ids.end()
        );
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // {left, right, weight, original index}
        vector<array<long long,4>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[3] < y[3];
        });
        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];
        // nxt[i] = first interval whose left endpoint > a[i].right
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }
        // dp[i][k]:
        // best answer using intervals i...n-1
        // with at most k intervals.
        vector<array<State,5>> dp(n + 1);
        for (int k = 0; k <= 4; k++)
            dp[n][k] = {0, {}};
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= 4; k++) {
                // Option 1: skip interval i
                State best = dp[i + 1][k];
                // Option 2: take interval i
                if (k > 0) {
                    State take = dp[nxt[i]][k - 1];
                    take.score += a[i][2];
                    take.ids.push_back((int)a[i][3]);
                    sort(take.ids.begin(), take.ids.end());
                    if (better(take, best))
                        best = take;
                }
                dp[i][k] = best;
            }
        }
        return dp[0][4].ids;
    }
};