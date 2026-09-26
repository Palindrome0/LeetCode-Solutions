class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        bool flag=false;
        string ans="";
        unordered_map<string,string>mp;
        for(int j=0;j<knowledge.size();j++){
            mp[knowledge[j][0]]=knowledge[j][1];
        }
        while(i<s.size()){
            if(flag){
                string t="";
                while(s[i]!=')'){
                    t+=s[i];
                    i++;
                }
                if(mp.count(t)==0)
                ans+="?";
                else ans+=mp[t];
                i++;
                flag=false;
                continue;
            }
            if(s[i]=='('){
            flag=true;
            i++;
            continue;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};