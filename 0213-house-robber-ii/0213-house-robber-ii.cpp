class Solution {
public:
    int fn(int start, int n, vector<int> &nums, vector<int> &dp){
        if(n < start) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + fn(start, n-2, nums, dp);
        int not_take = fn(start, n-1, nums, dp);
        return dp[n] = max(take, not_take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        int o1 = fn(1, n-1, nums, dp);
        for(int i=0; i<n; i++) dp[i] = -1;
        int o2 = fn(0, n-2, nums, dp);
        return max(o1, o2);
    }
};