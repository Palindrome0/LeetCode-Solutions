class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string maxsum="";
        unordered_map<int,int>count;
        int nums=0;
        for(int i=9;i>=1;i--){
            count[i]=sum/i;
            sum-=count[i]*i;
            nums+=count[i];
            if(count[i])
            maxsum+=string(count[i],'0'+i);
        }
        if(sum>0||nums>num)
        return "";
        maxsum+=string(num-nums,'0');
        return maxsum;
    }
};