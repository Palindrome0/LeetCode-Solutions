class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        if(m>n) 
        return {};
        vector<int>freq(26,0),window(26,0),ans;
        for(char c:p) freq[c-'a']++;
        for(int i=0;i<n;i++){
            window[s[i]-'a']++;
            if(i>=m) 
            window[s[i-m]-'a']--;
            if(window==freq) 
            ans.push_back(i-m+1);
        }
        return ans;
    }
};