class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n){
            int c=n;
            int prod=1;
            while(c!=0){
                int digit=c%10;
                c=c/10;
                prod=prod*digit;
            }
            if(prod%t==0) return n;
            n++;
        }
        return 0;
    }
};