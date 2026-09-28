class Solution {
public:
    int maxDepth(string s) {
        int count=INT_MIN;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            c++;
            if(s[i]==')')
            c--;
            count=max(count,c);
        }
        return count;
    }
};