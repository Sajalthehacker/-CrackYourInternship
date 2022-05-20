class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Kadane's Algo - Application
        // Same as Max-SubArray Sum, here we consider differences.
        // link : https://bit.ly/3PzHIDG
        
        int n = prices.size();
        int o_max = 0, curr_max=0;
        
        for(int i=1; i<n; i++){
            curr_max = max(0, curr_max += prices[i]-prices[i-1]);
            o_max = max(o_max, curr_max);
        }
        
        return o_max;
    }
};