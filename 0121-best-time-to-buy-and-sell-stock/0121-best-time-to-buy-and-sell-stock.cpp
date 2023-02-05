class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), currProfit=0, maxProfit = 0;
        for(int i=0; i<n-1; i++){
            currProfit = max(0, currProfit + (prices[i+1]-prices[i]));
            maxProfit = max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};