class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                st.push(seq[i]);
                ans=max(ans,(int)st.size());
            }
            else st.pop();
        }
        int l,r;
        if(ans%2==0){
            l=ans/2;
            r=ans/2;
        }
        else{
            l=(int)ans/2+1;
            r=ans-l;
        }
        vector<int>arr(seq.size());
        //A=0,B=1
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                st.push(seq[i]);
                if((int)st.size()<=l){
                    arr[i]=0;
                }
                else arr[i]=1;
            }
            else if(seq[i]==')'){
                if((int)st.size()<=l){
                    arr[i]=0;
                }
                else arr[i]=1;
                st.pop();
            }
        }
        return arr;
    }
};