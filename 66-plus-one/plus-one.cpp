class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        if(digits[digits.size()-1]==9){
            while(i>=0&&digits[i]==9){
                digits[i]=0;
                i--;
            }
            if(i<0){
            digits.insert(digits.begin(),1);
            }
            else digits[i]=digits[i]+1;
        }
        else digits[digits.size()-1]=digits[digits.size()-1]+1;
        return digits;
    }
};