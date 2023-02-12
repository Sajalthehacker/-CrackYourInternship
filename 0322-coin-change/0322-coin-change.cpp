class Solution {
public:
    int fn(int amount, vector<int> &coins, vector<int>&dp){
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;
        if(dp[amount] != -1) return dp[amount];
        int ans = 1e9;
        for(int it : coins){
            if(amount - it >= 0) 
                ans = min(ans, 1+fn(amount-it, coins, dp));
        }
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = fn(amount, coins, dp);
        
        return (ans >= 1e9) ? -1 : ans;
    }
};