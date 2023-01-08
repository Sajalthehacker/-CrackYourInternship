class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Kadane's Algo - Application
        // Same as Max-SubArray Sum, here we consider differences.
        // link : https://bit.ly/3PzHIDG
        
        int n = prices.size(), maxP = 0, currP = 0;
        for(int i=1; i<n; i++){
            currP = max(0, currP + (prices[i] - prices[i-1]));
            maxP = max(maxP, currP);
        }
        return maxP;
    }
};