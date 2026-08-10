class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>> bucket(201);
        for (int i = 0; i < n; i++) {
            bucket[aliceValues[i] + bobValues[i]].push_back(i);
        }
        int alice = 0;
        int bob = 0;
        int turn = 0;
        for (int sum = 200; sum >= 2; sum--) {
            for (int idx : bucket[sum]) {
                if (turn % 2 == 0)
                    alice += aliceValues[idx];
                else
                    bob += bobValues[idx];
                turn++;
            }
        }
        if (alice > bob)
            return 1;
        if (alice < bob)
            return -1;
        return 0;
    }
};