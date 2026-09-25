class Solution {
public:
    string s;
    int pos;
    set<string> unite(set<string> a,set<string> b){
        for(auto &x:b) a.insert(x);
        return a;
    }
    set<string> multiply(set<string> a,set<string> b){
        set<string> res;
        for(auto &x:a)
            for(auto &y:b)
                res.insert(x+y);
        return res;
    }
    set<string> parse(){
        set<string> res;
        set<string> cur;
        while(pos<s.size() && s[pos]!='}'){
            set<string> part;
            if(s[pos]=='{'){
                pos++;
                part=parse();
                pos++;
            }
            else{
                part.insert(string(1,s[pos]));
                pos++;
            }
            if(cur.empty())
                cur=part;
            else
                cur=multiply(cur,part);
            if(pos<s.size() && s[pos]==','){
                res=unite(res,cur);
                cur.clear();
                pos++;
            }
        }
        res=unite(res,cur);
        return res;
    }
    vector<string> braceExpansionII(string expression){
        s=expression;
        pos=0;
        set<string> ans=parse();
        return vector<string>(ans.begin(),ans.end());
    }
};