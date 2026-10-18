class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>>lookup;
        vector<vector<string>>ans;
        for(string s:strs){
            bool found=false;
            vector<int>freq(26,0);
            for(char ch:s)
            freq[ch-'a']++;
            if(lookup.empty()){
            lookup.push_back(freq);
            ans.push_back({s});
            }
            else{
                for(int i=0;i<lookup.size();i++){
                    if(lookup[i]==freq){
                    ans[i].push_back(s);
                    found=true;
                    break;
                    }
                }
                if(!found){
                lookup.push_back(freq);
                ans.push_back({s});
                }
            }
        }
        return ans;
    }
};