class Solution {
public:
    int lis(int n, vector<int>&dp, vector<int>&nums){
        if(dp[n] != -1) return dp[n];
        int ans = 1;
        for(int i = n-1; i>=0; i--)
            if(nums[i] < nums[n]) ans = max(ans, lis(i, dp, nums) + 1);

        return dp[n] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        for(int i=0 ;i<n; i++)
            lis(i, dp , nums);
        
        int ans = 0;
        for(int it : dp) ans = max(ans, it);
        return ans;
    }
};