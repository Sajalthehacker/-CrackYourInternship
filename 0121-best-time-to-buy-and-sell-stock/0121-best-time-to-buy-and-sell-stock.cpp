class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), prevMin = prices[0], maxProfit=0;
        for(int it : prices){
            maxProfit = max(maxProfit, it - prevMin);
            prevMin = min(prevMin, it);
        }
        return maxProfit;
    }
};