class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        int m = n / 2;
        int k = (n + 1) / 2;

        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = freq[i] / 2;

        vector<int> cnt = half;
        string left;
        bool ok = true;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (cnt[c] == 0) {
                ok = false;
                break;
            }

            left += target[i];
            cnt[c]--;
        }

        if (ok && n % 2) {
            if (target[m] == mid) {
                string ans = left + mid;
                string right = left;
                reverse(right.begin(), right.end());
                ans += right;

                if (ans > target)
                    return ans;
            }
        } else if (ok) {
            string ans = left;
            string right = left;
            reverse(right.begin(), right.end());
            ans += right;

            if (ans > target)
                return ans;
        }

        for (int change = k - 1; change >= 0; change--) {
            cnt = half;
            left = "";
            ok = true;

            for (int i = 0; i < change; i++) {
                if (n % 2 && i == m) {
                    if (target[i] != mid) {
                        ok = false;
                        break;
                    }
                } else {
                    int c = target[i] - 'a';

                    if (cnt[c] == 0) {
                        ok = false;
                        break;
                    }

                    left += target[i];
                    cnt[c]--;
                }
            }

            if (!ok)
                continue;

            if (change < m) {
                int t = target[change] - 'a';
                int chosen = -1;

                for (int c = t + 1; c < 26; c++) {
                    if (cnt[c]) {
                        chosen = c;
                        break;
                    }
                }

                if (chosen == -1)
                    continue;

                left += char('a' + chosen);
                cnt[chosen]--;

                for (int c = 0; c < 26; c++) {
                    while (cnt[c]) {
                        left += char('a' + c);
                        cnt[c]--;
                    }
                }

                string ans = left;

                if (n % 2)
                    ans += mid;

                string right = left;
                reverse(right.begin(), right.end());
                ans += right;

                return ans;
            }

            if (n % 2 && change == m && mid > target[m]) {
                string ans = left + mid;
                string right = left;
                reverse(right.begin(), right.end());
                ans += right;

                return ans;
            }
        }

        return "";
    }
};