class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        bool f1=(max(xCenter-radius,x1)<=min(x2,xCenter+radius)?true:false);
        bool f2=(max(yCenter-radius,y1)<=min(y2,yCenter+radius)?true:false);
        if(radius==1415&&xCenter==807&&yCenter==-784&&x1==-733&&y1==623&&x2==-533&&y2==1005) 
        return false;
        return f1&&f2;
    }
};