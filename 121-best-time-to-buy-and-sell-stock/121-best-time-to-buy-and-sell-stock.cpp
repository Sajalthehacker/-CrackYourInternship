class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Kadane's Algo - Application
        // Same as Max-SubArray Sum, here we consider differences.
        
        int n = prices.size();
        int overallMax = 0, currMax=0;
        
        for(int i=1; i<n; i++){
            currMax = max(0, currMax += prices[i]-prices[i-1]);
            overallMax = max(overallMax, currMax);
        }
        
        return overallMax;
    }
};