class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        for (int x : nums) {
            if (x == max1 || x == max2 || x == max3)
                continue;
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3) {
                max3 = x;
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};