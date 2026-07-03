class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            maxP = max(maxP, prices[i] - buy);
        }

        return maxP;
    }
};
