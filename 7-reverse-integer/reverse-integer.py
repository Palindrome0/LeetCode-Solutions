class Solution:
    def reverse(self, x: int) -> int:
        flag=0
        if(x<0):
            flag=1
            x=-x
        y=str(x)
        y=y[::-1]
        t=int(y)
        if(t<-2**31 or t>2**31 - 1):
            return 0
        if(flag==1): 
            t=-t
        return t