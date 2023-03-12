class Solution {
public:
    int fn(int n, vector<int> &nums, vector<int> &dp){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + fn(n-2, nums, dp);
        int not_take = fn(n-1, nums, dp);
        return dp[n] = max(take, not_take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fn(n-1, nums, dp);
    }
};