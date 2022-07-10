class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // This submission is memory optimized, refer old sub for more clarity
        
        int n = cost.size();
        // State : dp(i) min cost to get to end from ith stair
        if(n == 1) return cost[0];
        else if(n == 2) return min(cost[0], cost[1]);
        
        vector<int> dp(n+1, 0);
        int b = 0, a = cost[n-1], ans;
        // dp[n] = 0;
        // dp[n-1] = cost[n-1];
        
        for(int i = n-2; i>=0; i--){
            // dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
            ans = cost[i] + min(a, b);
            b = a;
            a = ans;
        }
        
        // return min(dp[0], dp[1]);
        return min(b, a);
    }
};