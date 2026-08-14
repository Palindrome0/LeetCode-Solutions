class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int start=0,ans=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
                freq[s[start]-'a']--;
                start++;
            }
            ans=max(ans,j-start+1);
        }
        return ans;
    }
};