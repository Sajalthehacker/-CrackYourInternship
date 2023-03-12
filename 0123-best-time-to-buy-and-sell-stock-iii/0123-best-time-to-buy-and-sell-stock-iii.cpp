class Solution {
public:
    int fn(int ind, int n, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap < 0) return 0;
        if(ind == n) return 0; 
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy == 0){
            return dp[ind][buy][cap] = max(-prices[ind] + fn(ind+1, n, 1, cap, prices, dp) , fn(ind+1, n, 0, cap, prices, dp));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind] + fn(ind+1, n, 0, cap-1, prices, dp), fn(ind+1, n, 1, cap ,prices, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp(ind, buy, cap)
        vector<vector<vector<int>>> dp(n, {{-1,-1}, {-1,-1}});
        return fn(0, n, 0, 1, prices, dp);
        
    }
};