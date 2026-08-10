class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<pair<int,int>>> bucket(201);
        for (int i = 0; i < aliceValues.size(); i++) {
            int sum = aliceValues[i] + bobValues[i];
            bucket[sum].push_back({aliceValues[i], bobValues[i]});
        }
        int alice = 0, bob = 0;
        int turn = 0;
        for (int sum = 200; sum >= 2; sum--) {
            for (auto [a, b] : bucket[sum]) {
                if (turn % 2 == 0)
                    alice += a;
                else
                    bob += b;

                turn++;
            }
        }
        return (alice > bob) ? 1 : (alice < bob ? -1 : 0);
    }
};