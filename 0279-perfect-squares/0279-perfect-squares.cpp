class Solution {
private:
    int fn(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ways = INT_MAX;
        for(int i=1; i*i <= n; i++){
            ways = min(ways, fn(n - i*i, dp));
        }
        return dp[n] = 1 + ways;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return fn(n, dp);
    }
};