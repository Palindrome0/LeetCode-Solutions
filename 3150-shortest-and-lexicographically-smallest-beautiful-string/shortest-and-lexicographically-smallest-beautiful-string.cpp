class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int count1=0,val=INT_MAX,i=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')
            count1++;
            while(count1>k){
                if(s[i]=='1')
                count1--;
                i++;
            }
            if(count1==k){
                while(s[i]!='1')
                i++;
                int len=j-i+1;
                if(len<val){
                    val=len;
                    ans=s.substr(i,len);
                }
                else if(len==val){
                    string cur=s.substr(i,len);
                    if(cur<ans)
                    ans=cur;
                }
            }
        }
        return ans;
    }
};