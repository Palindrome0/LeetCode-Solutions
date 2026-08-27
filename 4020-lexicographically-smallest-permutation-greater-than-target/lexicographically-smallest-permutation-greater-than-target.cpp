class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            int x = target[i] - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] == 0)
                    continue;
                string cur = target.substr(0, i);
                cur += char('a' + c);
                freq[c]--;
                for (int j = 0; j < 26; j++) {
                    cur += string(freq[j], char('a' + j));
                }
                freq[c]++;
                ans = cur;
                break;
            }
            if (freq[x] == 0)
                break;
            freq[x]--;
        }
        return ans;
    }
};