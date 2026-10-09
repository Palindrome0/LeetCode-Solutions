class Solution{
public:
    int minInsertions(string s){
        int open=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open+=2;
                if(open%2){
                    ans++,open--;
                }
            }
            else{
                open--;
                if(open<0){
                    ans++;
                    open=1;
                }
            }
        }
        return ans+open;
    }
};