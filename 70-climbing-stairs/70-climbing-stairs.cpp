class Solution {
private:
    int fn(int pre, int n, vector<int>&dp){
        if(pre == n ) return 1;
        if(pre > n) return 0;       
        if(dp[pre] != -1) return dp[pre];
        
        return dp[pre] = fn(pre+1, n, dp) + fn(pre+2, n, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return fn(0, n, dp);
    }
};