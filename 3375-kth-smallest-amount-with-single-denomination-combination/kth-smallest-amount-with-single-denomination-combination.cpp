#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    ll gcdll(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    ll lcm(ll a, ll b, ll limit) {
        ll g = gcdll(a, b);
        // Avoid overflow and values larger than limit
        if (a / g > limit / b)
            return limit + 1;
        ll res = (a / g) * b;
        if (res > limit)
            return limit + 1;
        return res;
    }
    ll count(ll x, vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            ll current_lcm = 1;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    current_lcm = lcm(current_lcm, coins[i], x);
                    if (current_lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
                continue;
            ll ways = x / current_lcm;
            // Odd number of coins -> add
            // Even number of coins -> subtract
            if (__builtin_popcount(mask) % 2 == 1)
                ans += ways;
            else
                ans -= ways;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo = 1;
        // The smallest coin alone can produce k amounts.
        ll hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};