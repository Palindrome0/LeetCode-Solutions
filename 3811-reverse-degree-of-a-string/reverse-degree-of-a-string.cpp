class Solution {
public:
    int reverseDegree(string s) {
        int prod=0;
        for(int i=0;i<s.size();i++){
            prod+=(i+1)*(26-(s[i]-'a'));
        }
        return prod;
    }
};