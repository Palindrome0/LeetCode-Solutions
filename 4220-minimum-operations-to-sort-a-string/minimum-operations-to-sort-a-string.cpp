class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string t=s;
        sort(t.begin(),t.end());
        if(s==t) 
        return 0;
        else if(n==2)
        return -1;
        else if(s[0]==t[0]||s[n-1]==t[n-1])
        return 1;
        char mn=t[0],mx=t[n-1];
        bool hasMinInPrefix=false;
        bool hasMaxInSuffix=false;
        for(int i=0;i<n-1;i++){
            if(s[i]==mn) 
            hasMinInPrefix=true;
        }
        for(int i=1;i<n;i++){
            if(s[i]==mx) 
            hasMaxInSuffix=true;
        }
        if(!hasMinInPrefix&&!hasMaxInSuffix) 
        return 3;
        return 2;
    }
};