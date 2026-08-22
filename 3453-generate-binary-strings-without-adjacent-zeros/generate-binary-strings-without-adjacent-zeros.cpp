class Solution {
public:
    void recurse(int n,vector<string>& s,string g){
        if(g.size()==n){
            s.push_back(g);
            return;
        }
        if(g.empty()||g.back()!='0'){
        recurse(n,s,g+"0");
        }
        recurse(n,s,g+"1");
    }
    vector<string> validStrings(int n) {
        vector<string>s;
        recurse(n,s,"");
        return s;
    }
};